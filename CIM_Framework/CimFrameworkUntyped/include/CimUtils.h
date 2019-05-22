//----------------------------------------------------------------------------
//
// Copyright (c) 2003 - 2012 Intel Corporation  All Rights Reserved.
//
//  File:       CimUtils.h
//
//  Contents:   Utility classes and functions for C++ CIM Framework, declarations
//
//----------------------------------------------------------------------------

#ifndef CIMUTILS_H
#define CIMUTILS_H 1

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <sstream>



#include "CimException.h"
#include "CimBasicNamespaces.h"

namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Utils 
{
	using std::istringstream;
	using std::ostringstream;
	using std::stringstream;
	using std::vector;
	using std::string;
	using Intel::Manageability::Exceptions::ConversionException;
	using Intel::Manageability::Cim::CimReference;



	// Each field of a CIM object is held as a name / value pair.
	// There's a wrinkle though; since XML allows multiple occurrences
	// of the same tag with different values, we need a vector of values
	// for each tag. For example:
	//
	// <foo>
	//	<bar>a</bar>
	//	<bar>b</bar>
	//	<bar>c</bar>
	// </foo>
	//
	// This maps to "foo" in the first item, and a vector with
	// "a", "b", and "c" in it as the second item.
	//
	// In practice, there will almost always be only one element
	// in the vector, but we have to be general and allow for what
	// the XML can convey.
	//typedef pair<bool, vector<string> > FieldValue;
	//typedef pair<string, FieldValue > FieldData;
	//typedef pair<string, vector<string> > FieldData;

	class FieldData {
	public:
		string name;
		vector<string> value;

		bool operator <(const FieldData &other) const
		{
			return (name < other.name);
		}
	};

	// CIM Objects can have more than one field, so we keep a vector
	// of FieldData.
	typedef vector< FieldData > VectorFieldData;

	// Define HexBinary type.
	typedef string HexBinary;

	// Define Int64 types.
	typedef long long Int64;
	typedef unsigned long long Uint64;

	// Define Base64 type. Used to encode certain kinds of
	// binary data, such as certificates and so on.
	class CIMUNTYPEDFRAMEWORK_API Base64
	{
	public:
		// Constructors
		Base64();
		Base64(const Base64& b);
		Base64(unsigned char *buffer, unsigned int blen);

		// encodedInput - base 64 encoded string 
		explicit Base64(const string& encodedInput);

		// Destructor
		~Base64();

		// Assignment
		Base64& operator =(const Base64& other);

		
		// Comparison
		bool operator==(const Base64 &other);
		bool operator!=(const Base64 &other);

		// Settors
		void Data(const unsigned char *buffer, const unsigned int blen);

		// encodedInput - base 64 encoded string
		void Data(const string& encodedInput);
		

		// Gettors
		const unsigned char* Data() const;
		const unsigned int Length() const;

		// Return string representation
		string TypeToString() const;

	private:
		unsigned char* data;
		unsigned int len;

	};

	// This converts different types to string and from string to
	// a value.
	
	
	
	class CIMUNTYPEDFRAMEWORK_API TypeConverter
	{
	private:
		static const size_t NUMBER_STRING_SIZE = 12;

		// template functions for converting Integers
		template<class T>
		static bool StringToUInteger(const string& str, T& t)
		{
			istringstream buffer(str);
			istringstream bufferCopy(str);
			long long tmp = 0;
			buffer >> tmp;
			if (buffer.fail() || tmp < 0)
				return false;
			unsigned long real_val;
			bufferCopy >> real_val;
			if (bufferCopy.fail())
				return false;

			t = (T)real_val;
			return true;
		}

		template<class T>
		static bool StringToInteger(const string& str, T& t)
		{
			istringstream buffer(str);
			long tmp;
			buffer >> tmp;
			if (buffer.fail())
				return false;

			t = (T)tmp;
			return true;		
		}
		
		template<class T>
		static string UIntegerToString(const T& number)
		{
			// int to string
			ostringstream buffer;
			unsigned long x = number;
			buffer << x;
			return buffer.str();
		}

		template<class T>
		static string IntegerToString(const T& number)
		{
			// int to string
			ostringstream buffer;
			long x = number;
			buffer << x;
			return buffer.str();
		}

		// template functions using streams (beware of use with char!) 
		template <class T>
		static string ToString(const T& t)
		{
			stringstream tmp;
			tmp << t;
			return tmp.str();
		}

		template <class T>
		static void FromString(const string& str, T& t)
		{
			stringstream tmp(str);
			tmp >> t;			
		}

	public:		
		//class ConversionException;
		
		// Other utility types go here.
		// Type conversion function declarations		
		static void StringToType(const string& str, int& t) ;	
		static string TypeToString(const int& str);
		static void StringToType(const string& str, unsigned int& t) ;	
		static string TypeToString(const unsigned int& str);
		static void StringToType(const string& str, char& t) ;
		static string TypeToString(const char& str);
		static void StringToType(const string& str, unsigned char& t) ;
		static string TypeToString(const unsigned char& str);
		static void StringToType(const string& str, short& t) ;
		static string TypeToString(const short& str);
		static void StringToType(const string& str, unsigned short& t) ;
		static string TypeToString(const unsigned short& str);
		static void StringToType(const string& str, unsigned long& t) ;
		static string TypeToString(const unsigned long& str);
		static void StringToType(const string& str, Int64& t);
		static string TypeToString(const Int64& str);
		static void StringToType(const string& str, Uint64& t);
		static string TypeToString(const Uint64& str);
		static void StringToType(const string& str, bool& t) ;
		static string TypeToString(const bool& str);		
		static void StringToType(const string& str, Base64& t);
		static string TypeToString(const Base64& buf);
		static void StringToType(const string& str, double& t);
		static string TypeToString(const double& str);
		static void StringToType(const string& str, string& t);
		static string TypeToString(const string& str);

		static void StringToType(const string& str, CimDateTime& t);
		static string TypeToString(const CimDateTime& t);

		static void StringToType(const string& str, CimReference& t);
		static string TypeToString(const CimReference& t);	

		template <class T>
		static void StringToType(const vector<string>& vec, T& t)
		{
			StringToType(vec[0], t);		
		}

		template <class T>
		static void StringToType(const vector<string>& vec, vector<T>& t)
		{
			t.clear();
			vector<string>::const_iterator iter;
			for (iter = vec.begin(); iter != vec.end(); iter++)
			{
				T temp;
				StringToType(*iter, temp);
				t.push_back(temp);
			}
		}

		template <class T>
		static vector<string> TypeToString(const vector<T>& vec)
		{
			vector<string> ret;
			typename vector<T>::const_iterator iter;
			for (iter = vec.begin(); iter != vec.end(); iter++)
			{
				string temp = TypeToString(*iter);
				ret.push_back(temp);
			}

			return ret;
		}
	};


}
}
}
}

#endif // CIMUTILS_H
