/*
 * Huffman.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: emip
 */

#include <iostream>
#include <string>
#include <map>

#include "CompareFreq.h"
#include "Huffman.h"

Huffman::Huffman() {
	// TODO Auto-generated constructor stub

}

Huffman::Huffman(const std::string data) {
	std::map<char,unsigned int>::iterator iter;
	std::pair<char,unsigned int> p;
	m_data = data;

	for(unsigned int i=0; i< data.length(); i++){ // On remplie la table des occurences
		m_occurences[data.at(i)]++;
	}

	for(iter = m_occurences.begin(); iter != m_occurences.end(); ++iter){
		p.first = iter->first;
		p.second = iter->second;
		m_freq.push(p);
	}
}

Huffman::~Huffman() {
	// TODO Auto-generated destructor stub
	//ceci est un test
}


//show

void Huffman::showOcc(){
	std::map<char,unsigned int>::iterator iter;
	std::cout << "Occurances of : " << m_data << std::endl;
	for(iter=m_occurences.begin();iter != m_occurences.end(); ++iter){
		std::cout << "\t- " << iter->first << " : " << iter->second << std::endl;
	}
}

