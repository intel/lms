//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimDateTime.h
//
//  Contents:   Classes for working with times and intervals, definitions.
//
//----------------------------------------------------------------------------


#ifndef CIMDATETIME_H
#define CIMDATETIME_H 1

#include <string>
#include <sstream>
#include <memory>


#include "CimUtils.h"

namespace Intel
{
	namespace Manageability
	{
		namespace Cim
		{
			using std::string;
			using std::shared_ptr;
			using Untyped::CimSerializer;

			class CIMUNTYPEDFRAMEWORK_API CimDateTimeBase
			{
			public:

				// Destructor.
				virtual ~CimDateTimeBase() {}

				// Properties
				virtual void DateTimeString(const string &value) = 0;
				virtual string DateTimeString() const = 0;

			protected:
				// Functions

				static bool IsValid(const string& date_time);

				template <typename T>
				static void SetField(const string& value, T& field)
				{
					std::istringstream stream(value);
					if (value.find_first_not_of('*') != string::npos)
					{
						stream >> field;
					}
					else
					{
						field = -1;
					}
					if (stream.fail())
					{
						throw std::invalid_argument("String is not a valid DateTime");
					}
				}

			};

			class CIMUNTYPEDFRAMEWORK_API CimDateTimeInterval : public CimDateTimeBase
			{
			public:

				// Ctors / Dtors

				explicit CimDateTimeInterval(long days = -1, short hours = -1, short minutes = -1,
					short seconds = -1, long microseconds = -1) :
					CimDateTimeBase(), _days(days), _hours(hours), _minutes(minutes), _seconds(seconds), _microseconds(microseconds)
				{
					Validate();
				}

				explicit CimDateTimeInterval(const string &interval_string);

				// Properties

				void Days(long days);
				const long Days() const { return _days; }

				void Hours(short hours);
				const short Hours() const { return _hours; }

				void Minutes(short minutes);
				const short Minutes() const { return _minutes; }

				void Seconds(short seconds);
				const short Seconds() const { return _seconds; }

				void Microseconds(long microseconds);
				const long Microseconds() const { return _microseconds; }

				virtual void DateTimeString(const string &value);
				virtual string DateTimeString() const;

			private:

				// Data

				long _days;
				short _hours;
				short _minutes;
				short _seconds;
				long _microseconds;

				// Functions

				void Validate() const;
			};

			class CIMUNTYPEDFRAMEWORK_API CimDateTimeAbsolute : public CimDateTimeBase
			{
			public:

				// Ctors / Dtors

				explicit CimDateTimeAbsolute(short year = -1, short month = -1, short day = -1,
					short hour = -1, short minute = -1, short second = -1, long microsecond = -1,
					short utc_offset = 0) :
					CimDateTimeBase(), _year(year), _month(month), _day(day),
					_hour(hour), _minute(minute), _second(second), _microsecond(microsecond), _utc_offset(utc_offset)
				{
					Validate();
				}

				explicit CimDateTimeAbsolute(const string &date_time);

				// Properties

				void Year(short year);
				const short Year() const { return _year; }

				void Month(short month);
				const short Month() const { return _month; }

				void Day(short day);
				const short Day() const { return _day; }

				void Hour(short hour);
				const short Hour() const { return _hour; }

				void Minute(short minute);
				const short Minute() const { return _minute; }

				void Second(short second);
				const short Second() const { return _second; }

				void Microsecond(long microsecond);
				const long Microsecond() const { return _microsecond; }

				void UtcOffset(short utc_offset) { _utc_offset = utc_offset; }
				const short UtcOffset() const { return _utc_offset; }

				virtual void DateTimeString(const string &value);
				virtual string DateTimeString() const;

			private:

				// Data

				short _year;
				short _month;
				short _day;
				short _hour;
				short _minute;
				short _second;
				long _microsecond;
				short _utc_offset;

				// Functions

				void Validate() const;
			};

			class CIMUNTYPEDFRAMEWORK_API CimDateTime
			{
			public:

				enum DateTimeType
				{
					DT_INTERVAL,
					DT_ABSOLUTE,
					DT_UNKNOWN
				};

				// Ctors / Dtors

				CimDateTime() : _type(DT_UNKNOWN) {}

				CimDateTime(const CimDateTimeAbsolute& date_time) : _type(DT_ABSOLUTE), _pImpl(new CimDateTimeAbsolute(date_time)) {}

				CimDateTime(const CimDateTimeInterval& date_time) : _type(DT_INTERVAL), _pImpl(new CimDateTimeInterval(date_time)) {}

				CimDateTime(const CimDateTime& other) : _type(other._type), _pImpl(Init_pImpl(other._pImpl)) {}

				virtual ~CimDateTime() {}

				// Operators

				// operator= param passed by value for swapping.
				CimDateTime& operator=(CimDateTime other);

				// Properties

				DateTimeType Type() const { return _type; }

				string DateTimeString() const;
				void DateTimeString(const string &value);

				// Functions

				void swap(CimDateTime& other);

				const CimDateTimeInterval& AsInterval() const;
				CimDateTimeInterval& AsInterval();

				const CimDateTimeAbsolute& AsAbsolute() const;
				CimDateTimeAbsolute& AsAbsolute();

				// Serialization functions
				string Serialize() const;
				void Deserialize(const string &str);

			private:

				// Data

				DateTimeType _type;
				shared_ptr<CimDateTimeBase> _pImpl;

				// Functions

				CimDateTimeBase* Init_pImpl(shared_ptr<CimDateTimeBase> other) const;

				// Type converstion member function templates for internal _pImpl casts
				template<typename T>
				const T& AsType() const
				{
					return dynamic_cast<const T&>(*_pImpl);
				}

			};

			void swap(CimDateTime& a, CimDateTime& b);
		}
	}
}

namespace std
{
	template<>
	void swap(Intel::Manageability::Cim::CimDateTime& a, Intel::Manageability::Cim::CimDateTime& b);
}

#endif // CIMDATETIME_H
