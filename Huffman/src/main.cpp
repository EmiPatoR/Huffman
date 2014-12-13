//============================================================================
// Name        : main.cpp
// Author      : HRUSTIC Emir
// Version     :
// Copyright   :
// Description : Huffman coding in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>

#include "Huffman.h"

using namespace std;

int main() {
	Tree* t = NULL;
	const std::string data = ("wikipedia");
	Huffman h(data);

	cout << "Hello world !" << endl; // prints

	//Test
	h.showOcc();
	//prior_q& test = h.getFreq();
	//node *n = NULL;

//	cout << "FREQ = " << endl;
//	while(!test.empty()){
//		n = test.top();
//		cout << "\t - " << n->key.first << " : " << n->key.second << endl;
//		test.pop();
//	}

	t = h.makeTree();
	cout << "DONE ." << endl;

	t->showTree();
	//cout << " TEST = " << t->getRoot()->key.second << endl;

	return 0;
}
