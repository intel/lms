/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2015 Intel Corporation
 */
#ifndef __PARSER_H__
#define __PARSER_H__

#include "MEIClientException.h"
#include <cstring>
#include <vector>

namespace Intel
{
namespace MEI_Client
{
/*
parses simple data from buffer to data field and validates that the buffer size is OK
[ simple data = with fixed length ]
parameters : t - the variable to which we want to parse the data
			 itr - iterator to the place in the buffer where the data is
			 end - an iterator that points after the end of the vector
increments the iterator to the place after the data
*/
template <class T>
void parseData (T& t,std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
{
	//check that buffer is large enough)
	if (end-itr<sizeof(T))
	{
		throw MEIClientException("Error: Buffer size is too small!");
	}
	uint8_t *p = (uint8_t*)&t;
	std::copy(itr,
		itr + sizeof(T),
		p);
	itr+=sizeof(T);
}
/*
parses simple data from buffer to array and validates that the buffer size is OK
[ simple data = with fixed length ]
parameters : t - the array to which we want to parse the data
			 itr - iterator to the place in the buffer where the data is
			 end - an iterator that points after the end of the vector
increments the iterator to the place after the data
*/
template <class T>
void parseArray (T *arr, int size, std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
{
	//check that buffer is large enough
	if (end-itr<(int)(sizeof(T)*size))
	{
		throw MEIClientException("Error: Buffer size is too small!");
	}
	uint8_t *p = (uint8_t*)arr;
	std::copy(itr, itr + sizeof(T)*size, p);
	itr+=sizeof(T)*size;
}

/*
template specialization for T = bool
*/
template <>
void parseData<bool> (bool &t,std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end);

/*
parses simple data from buffer to vector, used with variable-length arrays
Use this when count parameter is uint32_t
[ simple data = with fixed length ]
parameters : v - the vector to which we want to parse the data
			end - an iterator that points after the end of the vector
			itr - iterator to the place in the buffer where the data is,
			we assume the data is : uint32_t which holds the size of the array, and after that the data
increments the iterator to the place after the data
assumption : v is empty
*/
template <class T>
void parseSimpleArray32 (std::vector<T>& v, std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
{
	//get size of array
	if (end-itr<sizeof(uint32_t))
	{
		throw MEIClientException("Error: Buffer size is too small!");
	}
	uint32_t count;
	uint8_t *p = (uint8_t*)&count;
	std::copy(itr, itr + sizeof(uint32_t), p);
	itr+=sizeof(uint32_t);

	//copy data
	if (end-itr<(int)(sizeof(T)*count))
	{
		throw MEIClientException("Error: Buffer size is too small!");
	}
	if (count==0)
		return;
	v.resize(count);
	p = (uint8_t*)&v[0];
	std::copy(itr, itr + sizeof(T)*count, p);

	itr+=(sizeof(T)*count);
}

/*
parses simple data from buffer to vector, used with variable-length arrays
Use this when count parameter is uint16_t
[ simple data = with fixed length ]
parameters : v - the vector to which we want to parse the data
			end - an iterator that points after the end of the vector
			itr - iterator to the place in the buffer where the data is,
			we assume the data is : uint32_t which holds the size of the array, and after that the data
increments the iterator to the place after the data
assumption : v is empty
*/
template <class T>
void parseSimpleArray16 (std::vector<T>& v, std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
{
	//get size of array
	if (end-itr<sizeof(uint16_t))
	{
		throw MEIClientException("Error: Buffer size is too small!");
	}
	uint16_t count;
	uint8_t *p = (uint8_t*)&count;
	std::copy(itr, itr + sizeof(uint16_t), p);
	itr+=sizeof(uint16_t);

	//copy data
	if (end-itr<(int)(sizeof(T)*count))
	{
		throw MEIClientException("Error: Buffer size is too small!");
	}
	if (count==0)
		return;
	v.resize(count);
	p = (uint8_t*)&v[0];
	std::copy(itr, itr + sizeof(T)*count, p);
	itr+=(sizeof(T)*count);
}

/*
parses complex data from buffer to vector, used with variable-length arrays
[ complex data = with non-fixed length ]
parameters : v - the vector to which we want to parse the data
			end - an iterator that points after the end of the vector
			itr - iterator to the place in the buffer where the data is,
			we assume the data is : uint32_t which holds the size of the array, and after that the data
increments the iterator to the place after the data
assumptions : v is empty
			  the complex type T has function "void parse(..)" which gets iterators to the buffer and its end, parses the data and
			 _increments_ the iterator. parse should check for buffer size
*/
template <class T>
void parseComplexArray (std::vector<T>& v,std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
{
	//get size of array
	if (end-itr<sizeof(uint32_t))
	{
		throw MEIClientException("Error: Buffer size is too small!");
	}
	uint32_t count;
	uint8_t *p = (uint8_t*)&count;
	std::copy(itr, itr + sizeof(uint32_t), p);
	itr+=sizeof(uint32_t);
	if (count==0)
		return;
	v.resize(count);
	
	//parse should check for buffer size
	for (uint32_t i = 0; i<count; ++i)
		v[i].parse(itr,end);
}
} // namespace MEI_Client
} // namespace Intel

#endif //__PARSER_H__