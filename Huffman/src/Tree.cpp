/*
 * Tree.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: emip
 */


#include <iostream>

#include "Tree.h"

Tree::Tree() {
	root = NULL;
}

Tree::Tree(node* r) {
	root = r;
}

Tree::Tree(const Tree& t){
	this->root = t.root;
}

Tree::~Tree() {
	//destroy_tree(root);
}

void Tree::destroy_tree(node *leaf){
	if(leaf!=NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

Tree& Tree::operator+=(const Tree &t){
	node* n = new node;
	n->key.first = '*';
	if(this->root == NULL){
		n->key.second = t.root->key.second;
	}
	else if(t.root == NULL){
		n->key.second = this->root->key.second;
	}
	else{
		n->key.second = this->root->key.second + t.root->key.second;
	}

	n->left = this->root;
	n->right = t.root;

	this->root = n;

	return *this;
}

const Tree Tree::operator+(const Tree &other) const {
	return Tree(*this) += other;
}

void Tree::showTree(){
	showTree(root);
}

void Tree::showTree(node* n){
	if(n!=NULL){
		showTree(n->left);
		showTree(n->right);
		std::cout << " " << n->key.second << " ";
	}
}


