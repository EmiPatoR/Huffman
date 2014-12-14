/*
 * CompareNodes.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: emip
 */
#include "Tree.h"
#include "CompareNodes.h"

bool CompareNodes::operator()(node* t1, node* t2) // Returns true if t1 is smaller than t2
{
	if (t1->key.second > t2->key.second) return true;

	if (t1->key.second == t2->key.second)
		if(t1->key.first > t2->key.first) return true;

	return false;
}
