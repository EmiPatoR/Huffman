/*
 * CompareNodes.h
 *
 *  Created on: Dec 13, 2014
 *      Author: emip
 */

#ifndef COMPARENODES_H_
#define COMPARENODES_H_

#include <utility>

#include "Tree.h"

class CompareNodes {
public:
	bool operator()(node* t1, node* t2); // Returns true if t1 is smaller than t2
};

#endif /* COMPARENODES_H_ */
