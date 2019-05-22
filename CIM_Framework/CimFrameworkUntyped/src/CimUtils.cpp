//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimUtils.cpp
//
//  Contents:   Utility classes and functions for C++ CIM Framework, implementation
//
//----------------------------------------------------------------------------

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>

#include "CimUtils.h"
#include "CimDateTime.h"
#include "CimReference.h"
#include "cencode.h"
#include "cdecode.h"



namespace Intel
{
	namespace Manageability
	{
		namespace Cim
		{
			namespace Utils
			{


				static const int MAX_STRING_SIZE = 21;
				static const int NUMBER_STRING_SIZE = 12;

				// utility functions
				static string ToBase64(unsigned char *in, int inlen)
				{
					if (!in)
					{
						return "";
					}
					char* out = new char[((inlen + 1) * 4) / 3 + 3];
					char* out_start = out;

					base64_encodestate state;
					base64_init_encodestate(&state);
					out += base64_encode_block((char *)in, inlen, out, &state);
					out += base64_encode_blockend(out, &state);

					*out = '\0';
					string tmp = out_start;
					delete[] out_start;
					return tmp;
				}

				static void FromBase64(const unsigned char *inStr,
					unsigned char *outStr,
					unsigned int  *outStrSize)
				{
					if (!inStr || !outStr)
						return;

					base64_decodestate state;
					base64_init_decodestate(&state);
					*outStrSize = base64_decode_block((const char *)inStr,
						strlen((const char *)inStr), (char*)outStr, &state);
				}

				Base64::Base64()
				{
					data = NULL;
					len = 0;
				}

				Base64::Base64(const Base64& b)
				{
					data = NULL;
					len = 0;
					Data(b.data, b.len);
				}

				Base64::Base64(unsigned char *buffer, unsigned int blen)
				{
					data = NULL;
					len = 0;
					Data(buffer, blen);
				}

				// encodedInput - base 64 encoded string
				Base64::Base64(const string& encodedInput)
				{
					data = NULL;
					len = 0;
					Data(encodedInput);
				}

				Base64::~Base64()
				{
					if (data)
					{
						delete[] data;
						data = NULL;
						len = 0;
					}
				}

				string Base64::TypeToString() const
				{
					return ToBase64(data, len);
				}

				// encodedInput - base 64 encoded string
				void Base64::Data(const string& encodedInput)
				{
					if (data)
					{
						delete[] data;
						data = NULL;
					}
					data = new unsigned char[((encodedInput.length()) * 3 / 4 + 1)];
					FromBase64((const unsigned char*)encodedInput.c_str(), data, &len);
				}

				void Base64::Data(const unsigned char *buffer, const unsigned int blen)
				{
					if (buffer)
					{
						if (data)
						{
							delete[] data;
							data = nullptr;
						}
						len = blen;
						data = new unsigned char[len];
						memcpy(data, buffer, len);
					}
				}

				Base64& Base64::operator =(const Base64& other)
				{
					if (this == &other) {
						return *this;
					}
					if (data && len > 0)
					{
						delete[] data;
						data = nullptr;
					}
					len = other.len;
					if (len > 0) {
						data = new unsigned char[len];
						memcpy(data, other.data, len);
					}
					return *this;
				}


				bool Base64::operator==(const Base64 &other)
				{
					if (len == other.Length() && memcmp(data, other.Data(), len) == 0)
						return true;
					return false;
				}

				bool Base64::operator!=(const Base64 &other)
				{
					return !(*this == other);
				}

				const unsigned char *Base64::Data() const
				{
					return data;
				}

				const unsigned int Base64::Length() const
				{
					return len;
				}

				void TypeConverter::StringToType(const string& str, int& t)
				{
					if (!StringToInteger(str, t))
					{
						throw ConversionException(
							string("The string ").append(str)
							.append(" could not be converted to type int.").c_str());
					}
				}

				string TypeConverter::TypeToString(const int& str)
				{
					return IntegerToString(str);
				}

				void TypeConverter::StringToType(const string& str, unsigned int& t)
				{
					if (!StringToUInteger(str, t))
					{
						throw ConversionException(
							string("The string ").append(str)
							.append(" could not be converted to type unsigned int.").c_str());
					}
				}

				string TypeConverter::TypeToString(const unsigned int& str)
				{
					return UIntegerToString(str);
				}

				void TypeConverter::StringToType(const string& str, char& t)
				{
					if (!StringToInteger(str, t))
					{
						throw ConversionException(
							string("The string ").append(str)
							.append(" could not be converted to type char.").c_str());
					}
				}

				string TypeConverter::TypeToString(const char& str)
				{
					return IntegerToString(str);
				}

				void TypeConverter::StringToType(const string& str, unsigned char& t)
				{
					if (!StringToUInteger(str, t))
					{
						throw ConversionException(
							string("The string ").append(str)
							.append(" could not be converted to type unsigned char.").c_str());
					}
				}

				string TypeConverter::TypeToString(const unsigned char& str)
				{
					return UIntegerToString(str);
				}

				void TypeConverter::StringToType(const string& str, short& t)
				{
					if (!StringToInteger(str, t))
					{
						throw ConversionException(
							string("The string ").append(str)
							.append(" could not be converted to type short.").c_str());
					}
				}

				string TypeConverter::TypeToString(const short& str)
				{
					return IntegerToString(str);
				}

				void TypeConverter::StringToType(const string& str, unsigned short& t)
				{
					if (!StringToUInteger(str, t))
					{
						throw ConversionException(
							string("The string ").append(str)
							.append(" could not be converted to type unsigned short.").c_str());
					}
				}

				string TypeConverter::TypeToString(const unsigned short& str)
				{
					return UIntegerToString(str);
				}

				void TypeConverter::StringToType(const string& str, unsigned long& t)
				{
					if (!StringToUInteger(str, t))
					{
						throw ConversionException(
							string("The string ").append(str)
							.append(" could not be converted to type unsigned long.").c_str());
					}
				}

				string TypeConverter::TypeToString(const unsigned long& str)
				{
					return UIntegerToString(str);
				}

				void TypeConverter::StringToType(const string& str, Int64& t)
				{
#if defined (_WIN32) || defined (_WIN64)

					t = _atoi64(str.c_str());
#else
					t = strtoll(str.c_str(), NULL, 10);
#endif
				}

				string TypeConverter::TypeToString(const Int64& str)
				{
					std::stringstream ss;
					ss << str;
					return ss.str();
				}

				void TypeConverter::StringToType(const string& str, Uint64& t)
				{
#if defined (_WIN32) || defined (_WIN64)

					t = _strtoui64(str.c_str(), 0, 0);
#else
					sscanf(str.c_str(), "%llu", &t);
#endif
				}

				string TypeConverter::TypeToString(const Uint64& str)
				{
					std::stringstream ss;
					ss << str;
					return ss.str();
				}

				void TypeConverter::StringToType(const string& str, bool& t)
				{
					if (str == "true" || str == "1")
					{
						t = true;
					}
					else if (str == "false" || str == "0")
					{
						t = false;
					}
					else
					{
						throw ConversionException(
							string("The string ").append(str)
							.append(" could not be converted to type boolean.").c_str());
					}
				}

				string TypeConverter::TypeToString(const bool& value)
				{
					return (value ? "true" : "false");
				}

				void TypeConverter::StringToType(const string& str, Base64& t)
				{
					t.Data(str);
				}

				string TypeConverter::TypeToString(const Base64& buf)
				{
					return buf.TypeToString();
				}

				void TypeConverter::StringToType(const string& str, double& t)
				{
					istringstream buffer(str);
					buffer >> t;
					if (buffer.fail())
					{
						throw ConversionException(
							string("The string ").append(str)
							.append(" could not be converted to type double.").c_str());
					}
				}

				string TypeConverter::TypeToString(const double& str)
				{
					if (str == 0)
					{
						return "0";
					}
					return ToString(str);
				}

				void TypeConverter::StringToType(const string& str, string& t)
				{
					t = str;
				}

				string TypeConverter::TypeToString(const string& str)
				{
					return str;
				}

				void TypeConverter::StringToType(const string& str, CimDateTime& t)
				{
					t.Deserialize(str);
				}

				string TypeConverter::TypeToString(const CimDateTime& t)
				{
					return t.Serialize();
				}

				void TypeConverter::StringToType(const string& str, CimReference& t)
				{
					t.Deserialize(str);
				}
				string TypeConverter::TypeToString(const CimReference& t)
				{
					return t.Serialize();
				}


			};
		};
	};
};
