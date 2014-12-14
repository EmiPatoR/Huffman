/*
 * Tree.h
 *
 *  Created on: Dec 13, 2014
 *      Author: emip
 */

#ifndef TREE_H_
#define TREE_H_

#include <utility>

//Definition d'un noeud/feuille


typedef std::pair<char,unsigned int> couple;

struct node{
	std::pair<char,unsigned int> key;
	node* left;
	node* right;
};


class Tree {
public:
	Tree();
	Tree(node* r);
	Tree(const Tree& t);
	virtual ~Tree();
	void insert(couple key);
	node* search(couple key);
	void showTree();
	void showTree(node *n);
	void destroy_tree();
	Tree& operator+=(const Tree &t);
	const Tree operator+(const Tree &other) const;

	//predicates
	static bool isLeaf(node *n);

	//Getters
	node* getRoot(){return root;}

private:
	void destroy_tree(node *leaf);
	void insert(couple key, node *leaf);
	node* search(couple key, node *leaf);
	node* root;
};

#endif /* TREE_H_ */
