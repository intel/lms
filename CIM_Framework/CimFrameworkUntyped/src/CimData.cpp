//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimData.cpp
//
//  Contents:   Classes for managing storage of name / value data, implementation.
//
//----------------------------------------------------------------------------

#include "CimData.h"


namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Untyped 
{
	CimData::theData::theData()
	{
		specified = false;
	}

	CimData::CimData()
	{
	}

	
	CimData::~CimData()
	{
		Clear();
	}

	const vector<string> CimData::GetField(const string &name) const
	{
		vector<string> ret;
		int i = FindMemberData(name);
		if (i < 0)
			throw CimPropertyException("GetField: no such field named \"" + name + "\"");
		else
			return _memberData[i].val;
	}

	// Change the value of an existing field
	void CimData::SetField(const string &name, const string &value) 
	{
		vector<string> values;
		values.push_back(value);
		SetField(name, values);
	}

	void CimData::SetField(const string &name, const vector<string> &value) 
	{
		int i = FindMemberData(name);
		if (i < 0)
			throw CimException("SetField: no such field named \"" + name + "\"");

		_memberData[i].val = value;
		_memberData[i].specified = true;
	}

	void CimData::AddField(const string &name, const vector<string> &value) 
	{
		theData temp;
		temp.name = name;
		temp.val = value;
		temp.specified = true;

		_memberData.push_back(temp);
	}

	void CimData::AddField(const string &name, const string &value)
	{
		vector<string> values;
		values.push_back(value);
		AddField(name, values);
	}

	void CimData::SetOrAddField(const string &name, const string &value)
	{
		vector<string> values;
		values.push_back(value);
		SetOrAddField(name, values);
	}

	void CimData::SetOrAddField(const string &name, const vector<string> &value)
	{
		int i = FindMemberData(name);

		if (i < 0)
			AddField(name, value);
		else
			SetField(name, value);
	}


	void CimData::Clear()
	{
		_memberData.clear();
	}

	void CimData::RemoveField(const string &name)
	{
		int i = FindMemberData(name);
		if (i < 0)
			return;

		_memberData[i].specified = false;
		_memberData[i].val.clear();
	}
			
	bool CimData::ContainsField(const string &name) const
	{
		int i = FindMemberData(name);
		return (i >= 0 && _memberData[i].specified);
	}

	int CimData::FindMemberData(const string &name) const
	{
		int i = 0;
		vector<theData>::const_iterator iter = _memberData.begin();
		for (; iter != _memberData.end(); iter++, i++)
		{
			if (iter->name == name)
				return i;
		}

		return -1;
	}

	const VectorFieldData CimData::GetAllFields() const
	{
		VectorFieldData ret;

		vector<theData>::const_iterator iter = _memberData.begin();
		for (; iter != _memberData.end(); iter++)
		{
			if (iter->specified)
			{
				FieldData t;
				t.name = iter->name;
				t.value = iter->val;
				ret.push_back(t);
			}
		}

		return ret;
	}

	void CimData::ResetFields(const VectorFieldData &fields)
	{
		Clear();
		UpdateFields(fields);
		
	}

	void CimData::UpdateFields(const VectorFieldData &fields)
	{
		VectorFieldData::const_iterator iter = fields.begin();
		for (; iter != fields.end(); iter++) 
		{
			SetOrAddField(iter->name, iter->value);
		}
	}
};
};
};
};
