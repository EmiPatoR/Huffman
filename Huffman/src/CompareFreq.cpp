/*
 * CompareFreq.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: emip
 */

#include "CompareFreq.h"

bool CompareFreq::operator()(std::pair<char,unsigned int>& t1, std::pair<char,unsigned int>& t2) // Returns true if t1 is earlier than t2
{
	if (t1.second > t2.second) return true;
	return false;
}
