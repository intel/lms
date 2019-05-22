//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:		CimBase.cpp 
//
//  Contents:	A typed interface to CIM objects, implementation.
//
//----------------------------------------------------------------------------

#include "CimBase.h"
#include "CimSerializer.h"
#if defined(_WIN32)  || defined(_WIN64)
	#include <Windows.h>
#else
	#include <pthread.h>
#endif // _WIN32 || _WIN64

namespace Intel
{
	namespace Manageability
	{
		namespace Cim
		{
			namespace Typed 
			{
#ifdef WIN32
				class CimCriticalSection
				{
				public:
					CimCriticalSection()
					{
						if (!InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x00000400))
							return;
					}
					~CimCriticalSection()
					{
						DeleteCriticalSection(&CriticalSection);
					}
					void EnterCimCriticalSection()
					{
						EnterCriticalSection(&CriticalSection);
					}
					void LeaveCimCriticalSection()
					{
						LeaveCriticalSection(&CriticalSection);
					}
				private:
					CRITICAL_SECTION CriticalSection;
				};
#else
				class CimCriticalSection
				{
				public:
					CimCriticalSection()
					{
						if (pthread_mutex_init(&cs_mutex, NULL)) 
							throw std::runtime_error("pthread_mutex_init failed");
					}
					~CimCriticalSection()
					{
						pthread_mutex_destroy(&cs_mutex);
					}
					void EnterCimCriticalSection()
					{
						if (pthread_mutex_lock(&cs_mutex))
							throw std::runtime_error("pthread_mutex_lock failed");
					}
					void LeaveCimCriticalSection()
					{
						if (pthread_mutex_unlock(&cs_mutex))
							throw std::runtime_error("pthread_mutex_unlock failed");
					}
				private:
					pthread_mutex_t cs_mutex;
			}; 
#endif // WIN32
				
				class CimCriticalSectionLockGuard
				{
					CimCriticalSection & cs_;
				public:
					CimCriticalSectionLockGuard(CimCriticalSection & cs) : cs_(cs) { cs_.EnterCimCriticalSection(); }
					~CimCriticalSectionLockGuard()  { cs_.LeaveCimCriticalSection(); }
				};
				
				CimParam::~CimParam()
				{
				}

				CimBase::CimBase()
					: _lateBindingObject()
				{
				}

				CimBase::CimBase(ICimWsmanClient *client, const string &objectName,
					const string &nameSpace, const string &prefix, const string &resourceURI)
					: _lateBindingObject(client, objectName, nameSpace, prefix, resourceURI)
				{
				}

				CimBase::CimBase(const CimObject &object)
					: _lateBindingObject(object)
				{

				}

				CimBase::~CimBase()
				{
				}

				const string& CimBase::ResourceURI() const
				{
					return _lateBindingObject.ResourceURI();
				}

				const string& CimBase::XmlNamespace() const
				{
					return _lateBindingObject.XmlNameSpace();
				}

				const string& CimBase::XmlPrefix() const
				{
					return _lateBindingObject.XmlPrefix();
				}

				const string& CimBase::ObjectType() const
				{
					return _lateBindingObject.ObjectType();
				}

				ICimWsmanClient *CimBase::WsmanClient() const
				{
					return _lateBindingObject.WsmanClient();
				}

				void CimBase::WsmanClient(ICimWsmanClient *client)
				{
					_lateBindingObject.WsmanClient(client);
				}

				CimReference CimBase::Reference() const
				{
					CimReference reference;
					CimObject::CimKeys keys = GetKeys();
					reference.Selectors(CimReference::KeysToWsManSelectors(keys.Keys()));
					reference.ResourceURI(this->ResourceURI());
					return reference;
				}

				const VectorFieldData CimBase::GetAllFields() const
				{
					// By using the metadata, which is per concrete class,
					// we assure that "slicing" works, and that we return only
					// the fields that are part of the object for the current type.
					VectorFieldData ret;
					vector<CimFieldAttribute>::const_iterator iter;
					const vector<CimFieldAttribute>& metadata = GetMetaData();
					for (iter = metadata.begin(); iter != metadata.end(); iter++)
					{
						if (ContainsField(iter->name))
						{
							FieldData temp;
							temp.name = iter->name;
							temp.value = GetField(iter->name);
							ret.push_back(temp);
						}
					}

					// Objects sort their fields lexicographically.
					std::sort(ret.begin(), ret.end());

					return ret;
				}

				const CimObject::CimKeys CimBase::GetKeys() const
				{
					CimObject::CimKeys ret;
					const vector<CimFieldAttribute>& metadata = GetMetaData();
					vector<CimFieldAttribute>::const_iterator iter;

					for (iter = metadata.begin(); iter != metadata.end(); iter++)
					{
						if (iter->iskey && ContainsField(iter->name))
						{
							ret.SetKey(iter->name, GetField(iter->name)[0], iter->isEmbeddedObject);
						}
					}
					return ret;
				}

				void CimBase::Delete(ICimWsmanClient *client, const CimReference &reference)
				{
					CimObject::Delete(client, reference);
				}

				void CimBase::Delete(ICimWsmanClient *client, const string &resourceURI, const CimKeys &keys)
				{
					CimObject::Delete(client, resourceURI, keys.CimObjectKeys());
				}

				// This one deletes the calling object only
				void CimBase::Delete()
				{
					// Create keys from inner data
					_lateBindingObject.Delete(GetKeys());
				}

				void CimBase::Get()
				{
					_lateBindingObject.Get(GetKeys());
				}

				void CimBase::Get(const CimBase::CimKeys &keys)
				{
					_lateBindingObject.Get(keys.CimObjectKeys());
				}

				void CimBase::Get(const CimReference &reference)
				{
					_lateBindingObject.Get(reference);
				}

				// "Special" Enumerate (return a vector of CimBase pointers)
				vector< shared_ptr<CimBase> > CimBase::Enumerate(ICimWsmanClient *client, const EnumerateFilter &filter)
				{		
					vector<shared_ptr<CimBase> > vec;
					vector<shared_ptr<CimObject> > objectVec = CimObject::Enumerate(client, filter);
					vector<shared_ptr<CimObject> >::const_iterator iter;

					for (iter = objectVec.begin(); iter != objectVec.end(); iter++)
					{
						CimBase *cur = CimClassFactory::CreateCimClass(**iter);
						shared_ptr<CimBase> cur_ptr(cur);
						vec.push_back(cur_ptr);
					}
					return vec;
				}

				// "Special" Enumerate (return a vector of CimReference pointers)
				vector< shared_ptr<CimReference> > CimBase::EnumerateRef(ICimWsmanClient *client, const EnumerateFilter &filter)
				{
					return CimObject::EnumerateRef(client, filter);
				}

				void CimBase::Put()
				{
					_lateBindingObject.Put(GetKeys());
				}

				CimReference CimBase::Create() const
				{
					CimReference reference = _lateBindingObject.Create();
					return reference;
				}

				unsigned int CimBase::Invoke(const string &methodName,
					const CimParam &input, CimParam &output)
				{
					Intel::Manageability::Cim::Untyped::CimParam inputTemp(input._cimParamObject);
					inputTemp.ResetFields(input.GetAllFields());
					return _lateBindingObject.Invoke(methodName, GetKeys(), inputTemp, output._cimParamObject);
				}

				string CimBase::Serialize(const string &name) const
				{
					string realName;
					if (name == "")
					{
						realName = ObjectType();
					}
					else
					{
						realName = name;
					}

					string ret = CimSerializer::GetSerializer()->Serialize(realName, XmlNamespace(), ResourceURI(), XmlPrefix(), GetAllFields(), false, (name == "" ? false : true));
					return ret;
				}

				void CimBase::Deserialize(const string &xml)
				{
					string objectName, nameSpace, prefix;
					VectorFieldData vfd;

					vfd = CimSerializer::GetSerializer()->Deserialize(xml);
					ResetFields(vfd);
				}

				const vector<string> CimBase::GetField(const string &name) const
				{
					return _lateBindingObject.GetField(name);
				}

				bool CimBase::ContainsField(const string &name) const
				{
					return _lateBindingObject.ContainsField(name);
				}

				void CimBase::RemoveField(const string &name)
				{
					_lateBindingObject.RemoveField(name);
				}

				void CimBase::SetOrAddField(const string &name, const string &value)
				{
					_lateBindingObject.SetOrAddField(name, value);
				}

				void CimBase::SetOrAddField(const string &name, const vector<string> &value)
				{
					_lateBindingObject.SetOrAddField(name, value);
				}

				void CimBase::ResetFields(const VectorFieldData &fields)
				{
					_lateBindingObject.ResetFields(fields);
				}

				const vector<CimFieldAttribute> &CimBase::GetMetaData() const
				{
					throw CimException("Internal error: call of CimBase::GetMetaData");
				}

				int CimBase::FindMetaData(const string &name) const
				{
					vector<CimFieldAttribute>::const_iterator iter;
					const vector<CimFieldAttribute> & metadata = GetMetaData();

					int i = 0;
					for (iter = metadata.begin(); iter != metadata.end(); iter++, i++)
					{
						if (iter->name == name)
							return i;
					}

					return -1;
				}

				bool CimBase::IsKey(const string &field) const
				{
					int i = FindMetaData(field);
					return (i >= 0) ? GetMetaData()[i].iskey : false;
				}

				bool CimBase::IsRequired(const string &field) const
				{
					int i = FindMetaData(field);
					return (i >= 0) ? GetMetaData()[i].isrequired : false;
				}

				void  CimBase::SetMetaData(vector<CimFieldAttribute>& resultVector, const CimFieldAttribute metadata[], int count)
				{	
					// race condition because of static vector<CimFieldAttribute> being populated from multiple threads
					// caused crash in RCS. 
					static CimCriticalSection section;
					

					try{
						CimCriticalSectionLockGuard lg(section);

						for (int i = 0; i < count; i++)
						{
							vector<CimFieldAttribute>::iterator iter;
							bool found = false;

							for (iter = resultVector.begin(); iter < resultVector.end(); iter++)
							{
								if (iter->name == metadata[i].name)
								{
									*iter = metadata[i];
									found = true;
									break;
								}
							}
							if (! found)
								resultVector.push_back(metadata[i]);
						}
					}
					catch(int){}
				}

				CimObject CimBase::GetUnTyped() const
				{
					return _lateBindingObject;
				}
			};
		};
	};
};
