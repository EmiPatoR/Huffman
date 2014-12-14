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
	//h.showOcc(); // Montre la table d'occurences
	//h.getTree()->showTree(); // Montre l'arbre ( Parcours en profondeur )
	h.showCode();
	return 0;
}
