// Created by jacob Marx
#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
	Node(int data = 0) {
		this->data = data;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	int data;
	Node* left;
	Node* right;
	Node* parent;
};
	
#endif