//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimDateTime.cpp
//
//  Contents:   Classes for working with times and intervals, implementation.
//
//----------------------------------------------------------------------------

#include <iomanip>
#include <cassert>

#include "CimDateTime.h"
#include "CimSerializer.h"


namespace Intel {
	namespace Manageability {
		namespace Cim {

			using Exceptions::ConversionException;
			using Exceptions::CimException;
			using namespace std;

			string CimDateTime::Serialize() const
			{
				return CimSerializer::GetSerializer()->SerializeDateTime(*this);
			}

			void CimDateTime::Deserialize(const string &str)
			{
				*this = CimSerializer::GetSerializer()->DeserializeDateTime(str);
			}

			CimDateTimeBase* CimDateTime::Init_pImpl(shared_ptr<CimDateTimeBase> other) const
			{
				switch (_type)
				{
				case DT_INTERVAL:
					return new CimDateTimeInterval(dynamic_cast<CimDateTimeInterval&>(*other));
				case DT_ABSOLUTE:
					return new CimDateTimeAbsolute(dynamic_cast<CimDateTimeAbsolute&>(*other));
				default:
					throw ConversionException("Not a valid type");
				}
			}

			bool CimDateTimeBase::IsValid(const string& date_time)
			{
				if (date_time.length() != 25 ||
					date_time[14] != '.' ||
					date_time.find_first_not_of(".:+-*0123456789") != string::npos ||
					date_time.find('*') < date_time.find_last_not_of("*.", 20))
				{
					return false;
				}
				return true;
			}

			CimDateTimeInterval::CimDateTimeInterval(const string &interval_string)
			{
				DateTimeString(interval_string);
			}

			void CimDateTimeInterval::DateTimeString(const string &value)
			{
				if (!IsValid(value))
				{
					throw invalid_argument("String is not a valid DateTime");
				}
				SetField(value.substr(0, 8), _days);
				SetField(value.substr(8, 2), _hours);
				SetField(value.substr(10, 2), _minutes);
				SetField(value.substr(12, 2), _seconds);
				if (value[20] == '*')
				{
					_microseconds = -1;
				}
				else
				{
					SetField(value.substr(15, 6), _microseconds);
				}
				if (value.substr(21) != ":000")
				{
					throw invalid_argument("String is not a valid DateTime");
				}
			}

			void CimDateTimeInterval::Days(long days)
			{
				_days = days;
				if (_days < 0)
				{
					Hours(-1);
				}
			}

			void CimDateTimeInterval::Hours(short hours)
			{
				_hours = hours;
				if (_hours < 0)
				{
					Minutes(-1);
				}
				else if (_days < 0)
				{
					Days(0);
				}
			}

			void CimDateTimeInterval::Minutes(short minutes)
			{
				_minutes = minutes;
				if (_minutes < 0)
				{
					Seconds(-1);
				}
				else if (_hours < 0)
				{
					Hours(0);
				}
			}

			void CimDateTimeInterval::Seconds(short seconds)
			{
				_seconds = seconds;
				if (_seconds < 0)
				{
					Microseconds(-1);
				}
				else if (_minutes < 0)
				{
					Minutes(0);
				}
			}

			void CimDateTimeInterval::Microseconds(long microseconds)
			{
				_microseconds = microseconds;
				if (_microseconds >= 0 && _seconds < 0)
				{
					Seconds(0);
				}
			}

			// Convert the CimDateTimeInterval class into string.
			string CimDateTimeInterval::DateTimeString() const
			{
				ostringstream significant_values;
				significant_values.fill('0');
				if (_days >= 0)
				{
					significant_values << setw(8) << _days;
					if (_hours >= 0)
					{
						significant_values << setw(2) << _hours;
						if (_minutes >= 0)
						{
							significant_values << setw(2) << _minutes;
							if (_seconds >= 0)
							{
								significant_values << setw(2) << _seconds;
							}
						}
					}
				}
				ostringstream ret;
				ret.fill('*');
				ret << setiosflags(ios::left) << setw(14) << significant_values.str()
					<< '.' << resetiosflags(ios::left);
				if (_microseconds >= 0)
				{
					assert(ret.str().find('*') == string::npos);
					ret.fill('0');
					ret << setw(6) << _microseconds;
				}
				else
				{
					ret << "******";
				}
				ret << ":000";
				assert(ret.str().length() == 25);
				return ret.str();
			}

			const CimDateTimeInterval& CimDateTime::AsInterval() const
			{
				return AsType<CimDateTimeInterval>();
			}

			CimDateTimeInterval& CimDateTime::AsInterval()
			{
				return const_cast<CimDateTimeInterval&>(static_cast<const CimDateTime*>(this)->AsInterval());
			}

			void CimDateTimeInterval::Validate() const
			{
				if (!IsValid(DateTimeString()))
				{
					throw invalid_argument("Invalid DateTime");
				}
			}

			CimDateTimeAbsolute::CimDateTimeAbsolute(const string &date_time)
			{
				DateTimeString(date_time);
			}

			void CimDateTimeAbsolute::DateTimeString(const string &value)
			{
				if (!IsValid(value))
				{
					throw invalid_argument("String is not a valid DateTime");
				}
				SetField(value.substr(0, 4), _year);
				SetField(value.substr(4, 2), _month);
				SetField(value.substr(6, 2), _day);
				SetField(value.substr(8, 2), _hour);
				SetField(value.substr(10, 2), _minute);
				SetField(value.substr(12, 2), _second);
				if (value[20] == '*')
				{
					_microsecond = -1;
				}
				else
				{
					SetField(value.substr(15, 6), _microsecond);
				}
				SetField(value.substr(21, 4), _utc_offset);
			}

			// Convert the CimDateTimeAbsolute class into string.
			string CimDateTimeAbsolute::DateTimeString() const
			{
				ostringstream significant_values;
				significant_values.fill('0');
				if (_year >= 0)
				{
					significant_values << setw(4) << _year;
					if (_month >= 0)
					{
						significant_values << setw(2) << _month;
						if (_day >= 0)
						{
							significant_values << setw(2) << _day;
							if (_hour >= 0)
							{
								significant_values << setw(2) << _hour;
								if (_minute >= 0)
								{
									significant_values << setw(2) << _minute;
									if (_second >= 0)
									{
										significant_values << setw(2) << _second;
									}
								}
							}
						}
					}
				}
				ostringstream ret;
				ret.fill('*');
				ret << setiosflags(ios::left) << setw(14) << significant_values.str()
					<< '.' << resetiosflags(ios::left);
				if (_microsecond >= 0)
				{
					assert(ret.str().find('*') == string::npos);
					ret.fill('0');
					ret << setw(6) << _microsecond;
				}
				else
				{
					ret << "******";
				}
				if (_utc_offset >= 0)
				{
					ret << '+';
				}
				else
				{
					ret << '-';
				}
				ret.fill('0');
				ret << setw(3) << abs(_utc_offset);
				assert(ret.str().length() == 25);
				return ret.str();
			}

			void CimDateTimeAbsolute::Year(short year)
			{
				if (year == 0)
				{
					throw invalid_argument("Year cannot be 0");
				}
				_year = year;
				if (_year < 0)
				{
					Month(-1);
				}
			}

			void CimDateTimeAbsolute::Month(short month)
			{
				if (month == 0)
				{
					throw invalid_argument("Month cannot be 0");
				}
				if (month > 12)
				{
					throw invalid_argument("Month cannot be over 12");
				}
				_month = month;
				if (_month < 0)
				{
					Day(-1);
				}
				else if (_year < 0)
				{
					Year(1);
				}
			}

			void CimDateTimeAbsolute::Day(short day)
			{
				if (day == 0)
				{
					throw invalid_argument("Day cannot be 0");
				}
				if (day > 31)
				{
					throw invalid_argument("Day cannot be over 31");
				}
				_day = day;
				if (_day < 0)
				{
					Hour(-1);
				}
				else if (_month < 0)
				{
					Month(1);
				}
			}

			void CimDateTimeAbsolute::Hour(short hour)
			{
				if (hour > 24)
				{
					throw invalid_argument("Hour cannot be over 24");
				}
				_hour = hour;
				if (_hour < 0)
				{
					Minute(-1);
				}
				else if (_day < 0)
				{
					Day(1);
				}
			}

			void CimDateTimeAbsolute::Minute(short minute)
			{
				if (minute > 60)
				{
					throw invalid_argument("Minute cannot be over 60");
				}
				_minute = minute;
				if (_minute < 0)
				{
					Second(-1);
				}
				else if (_hour < 0)
				{
					Hour(0);
				}
			}

			void CimDateTimeAbsolute::Second(short second)
			{
				if (second > 60)
				{
					throw invalid_argument("Second cannot be over 60");
				}
				_second = second;
				if (_second < 0)
				{
					Microsecond(-1);
				}
				else if (_minute < 0)
				{
					Minute(0);
				}
			}

			void CimDateTimeAbsolute::Microsecond(long microsecond)
			{
				_microsecond = microsecond;
				if (_microsecond >= 0 && _second < 0)
				{
					Second(0);
				}
			}

			void CimDateTimeAbsolute::Validate() const
			{
				if (_year == 0 || _month == 0 || _day == 0)
				{
					throw invalid_argument("Invalid Date");
				}
				if (!IsValid(DateTimeString()))
				{
					throw invalid_argument("Invalid DateTime");
				}
			}

			const CimDateTimeAbsolute& CimDateTime::AsAbsolute() const
			{
				return AsType<CimDateTimeAbsolute>();
			}

			CimDateTimeAbsolute& CimDateTime::AsAbsolute()
			{
				return const_cast<CimDateTimeAbsolute&>(static_cast<const CimDateTime*>(this)->AsAbsolute());
			}

			string CimDateTime::DateTimeString() const
			{
				return _pImpl->DateTimeString();
			}

			void CimDateTime::DateTimeString(const string &value)
			{
				_pImpl->DateTimeString(value);
			}

			void CimDateTime::swap(CimDateTime& other)
			{
				using std::swap;

				swap(_pImpl, other._pImpl);
				swap(_type, other._type);
			}

			// operator= param passed by value for swapping.
			CimDateTime& CimDateTime::operator=(CimDateTime other)
			{
				swap(other);
				return *this;
			}

			void swap(CimDateTime& a, CimDateTime& b)
			{
				a.swap(b);
			}
		}
	}
}

namespace std
{
	template<>
	void swap(Intel::Manageability::Cim::CimDateTime& a, Intel::Manageability::Cim::CimDateTime& b)
	{
		Intel::Manageability::Cim::swap(a, b);
	}
}
