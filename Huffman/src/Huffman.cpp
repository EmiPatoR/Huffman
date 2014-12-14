/*
 * Huffman.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: emip
 */

#include <iostream>
#include <string>
#include <map>

#include "CompareNodes.h"
#include "Huffman.h"

Huffman::Huffman() {
	m_leaves = NULL;
	m_Huffman_tree = NULL;
	m_code = std::string("");
}

Huffman::Huffman(const std::string data) {
	std::map<char,unsigned int>::iterator iter;
	std::pair<char,unsigned int> p;
	unsigned int i=0;

	m_data = data;
	m_code = std::string("");

	for(unsigned int i=0; i< data.length(); i++){ // On remplie la table des occurences
		m_occurences[data.at(i)]++;
	}

	m_leaves = new node*[m_occurences.size()];

	for(iter = m_occurences.begin(); iter != m_occurences.end(); ++iter){
		m_leaves[i] = new node;
		m_leaves[i]->left = NULL;
		m_leaves[i]->right = NULL;
		p.first = iter->first;
		p.second = iter->second;
		m_leaves[i]->key = p;
		m_freq.push(m_leaves[i]);
		i++;
	}

	m_Huffman_tree = makeTree(); // On fabrique l'arbre
	decode(); // On retrouve les codes de chaque caractere
	genCode(); // On genere le code
}

Huffman::~Huffman() {
	if(m_leaves != NULL)
		delete [] m_leaves;

	if(m_Huffman_tree != NULL)
		delete m_Huffman_tree;

}

//show

void Huffman::showOcc(){
	std::map<char,unsigned int>::iterator iter;
	std::cout << "Occurances of : " << m_data << std::endl;
	for(iter=m_occurences.begin();iter != m_occurences.end(); ++iter){
		std::cout << "\t- " << iter->first << " : " << iter->second << std::endl;
	}
}

//Methods

Tree* Huffman::makeTree(){
	Tree* resultat = NULL;
	Tree temp;
	node *n1;
	node *n2;
	Tree t1;
	Tree t2;

	while(m_freq.size() > 1){

		n1 = m_freq.top();
		m_freq.pop();
		n2 = m_freq.top();
		m_freq.pop();

		t1 = Tree(n1);
		t2 = Tree(n2);

		temp = t1 + t2;

		m_freq.push(temp.getRoot());
	}
	n1 = m_freq.top();
	m_freq.pop();
	resultat = new Tree(n1);
	return resultat;
}

void Huffman::visit(node* n,std::string code){
	if(n != NULL){
		if(Tree::isLeaf(n)){
			m_encode[n->key.first] = code;
		}
		else{
			visit(n->left, code + "0");
			visit(n->right,code + "1");
		}
	}
}

void Huffman::decode(){
	visit(m_Huffman_tree->getRoot(),"");
}

void Huffman::genCode(){
	if(m_code != "")
		m_code = "";

	for(unsigned int i=0;i<m_data.length();i++){
		if(i == m_data.length()-1)
			m_code = m_code + m_encode[m_data[i]];
		else
			m_code = m_code + m_encode[m_data[i]] + " ";
	}
}

void Huffman::showCode(){
	std::cout << "Le code de Huffman pour " << m_data << " est : " << m_code << std::endl;
	std::cout << "Codage ASCII (7 Bits par caractere) = " << 7*m_data.length() << std::endl;
	std::cout << "Codage de Huffman : " << m_code.length() - (m_data.length() - 1) << std::endl;
}
