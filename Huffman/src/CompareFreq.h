/*
 * CompareFreq.h
 *
 *  Created on: Dec 13, 2014
 *      Author: emip
 */

#ifndef COMPAREFREQ_H_
#define COMPAREFREQ_H_

#include <utility>

class CompareFreq {
public:
	bool operator()(std::pair<char,unsigned int>& t1, std::pair<char,unsigned int>& t2); // Returns true if t1 is smaller than t2
};

#endif /* COMPAREFREQ_H_ */
