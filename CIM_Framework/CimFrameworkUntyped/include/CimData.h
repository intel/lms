//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2021  All Rights Reserved.
//
//  File:       CimData.h
//
//  Contents:   Classes for managing storage of name / value data, declarations.
//
//----------------------------------------------------------------------------

#ifndef CIMDATA_H
#define CIMDATA_H 1

#include <string>
#include "CimUntypedDllExport.h"
#include "CimBasicNamespaces.h"
#include "CimUtils.h"
#include "CimException.h"
#include "CimReference.h"



namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Untyped 
{
	using std::string;
	using std::vector;
	using Intel::Manageability::Exceptions::CimException;
	using Intel::Manageability::Exceptions::CimPropertyException;
	using Intel::Manageability::Cim::Utils::VectorFieldData;
	using Intel::Manageability::Cim::Utils::FieldData;;



	

	// This class maintains the name / value mappings and provides access
	// to each field and its data.  This class ONLY manages data; CIM class
	// methods (such as get, put, etc.) are in a derived class. Doing things
	// this way provides a clean separation for derived classes that are data-only,
	// such as those representing parameters to method invocations.
	class CIMUNTYPEDFRAMEWORK_API CimData {
	
	public:
		// Constructors.
		CimData();
		//CimData(const CimData &Other);
		

		// Destructor.
		virtual ~CimData () = 0;

		// For now, we don't see a real need for a hand-written
		// operator=() function; the compiler will generate one
		// that "ought" to work.  This comment serves to document
		// that the lack of an operator=() is an explicit decision.
		//CimData& operator=(const CimData& other);

	
		

		// Access to fields
		// Get a field's value(s)
		// If the field does not exist throw CimException
		const vector<string> GetField(const string &name) const ;
		

		void SetOrAddField(const string &name, const string &value) ;
		void SetOrAddField(const string &name, const vector<string> &value) ;

		// Empty out the list of fields.
		void Clear();

		// Remove a single field and its value.
		void RemoveField(const string &name);

		// Return true if the object has the field name.
		bool ContainsField(const string &name) const;


		// Get the fields in the order in which they were added.
		const VectorFieldData GetAllFields() const;

		// Set the fields in the order they are in the fields parameter.
		// This clears out any existing values first.
		void ResetFields(const VectorFieldData &fields);


	protected:
		// Set the fields in the order they are in the fields parameter.
		// This does not mess with any other fields.
		void UpdateFields(const VectorFieldData &fields);

		// This struct holds the data for each member.
		// The specified member indicates that a value has been
		// assigned to this element.  Only those elements which
		// have been assigned are exported to callers.
		struct theData {
			string name;
			vector<string> val;
			bool specified;
			theData();
		};
		vector<theData> _memberData;

		

	private:
		// Finds position in _memberData vector
		// Returns -1 if name is not found.
		int FindMemberData(const string &name) const;

		// Set a field's value(s)
		void SetField(const string &name, const string &value) ;
		void SetField(const string &name, const vector<string> &value) ;

		void AddField(const string &name, const vector<string> &value) ;
		void AddField(const string &name, const string &value) ;

	};

};
};
};
};

#endif // CIMDATA_H
