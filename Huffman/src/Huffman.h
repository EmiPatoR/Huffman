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
	Tree* m_Huffman_tree;
	std::map<char, std::string> m_encode;
	std::string m_code;

public:
	//Constructors
	Huffman(void);
	Huffman(const std::string data);

	//Destructors
	virtual ~Huffman(void);

	//Getters
	std::string getData(void){return m_data;}
	std::map<char,unsigned int>& getOcc(void){return m_occurences;}
	prior_q& getFreq(void){return m_freq;}
	Tree* getTree(void){return m_Huffman_tree;}
	std::map<char,std::string> getEncode(void){return m_encode;}
	std::string getCode(void){return m_code;}

	//private
	void genCode(void);
	void visit(node* n,std::string code);
	Tree* makeTree(void);
	void decode(void);

	//show
	void showOcc(void);
	void showCode(void);

};

#endif /* HUFFMAN_H_ */
