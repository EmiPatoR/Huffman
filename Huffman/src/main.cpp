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

	const std::string data = ("wikipedia");
	Huffman h(data);

	cout << "Hello world !" << endl; // prints

	//Test
	h.showOcc();
	prior_q& test = h.getFreq();
	std::pair<char, unsigned int> p;

	cout << "FREQ = " << endl;
	while(!test.empty()){
		p.first = test.top().first;
		p.second = test.top().second;

		cout << "\t - " << p.first << " : " << p.second << endl;
		test.pop();
	}

	return 0;
}
