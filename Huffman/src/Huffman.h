/*
 * Huffman.h
 *
 *  Created on: Dec 13, 2014
 *      Author: emip
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <functional>

#include "Tree.h"
#include "CompareNodes.h"

typedef std::priority_queue<node*,std::vector<node*>, CompareNodes> prior_q;

class Huffman {
private:
	std::string m_data;
	std::map<char,unsigned int> m_occurences;
	prior_q m_freq;
	node** m_leaves;

public:
	//Constructors
	Huffman();
	Huffman(const std::string data);

	//Destructors
	virtual ~Huffman();

	//Getters
	std::string getData(void){return m_data;}
	std::map<char,unsigned int>& getOcc(void){return m_occurences;}
	prior_q& getFreq(void){return m_freq;}

	//show
	void showOcc(void);

	//Methods
	Tree* makeTree();

};

#endif /* HUFFMAN_H_ */
