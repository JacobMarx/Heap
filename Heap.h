// Created by Jacob Marx on 3/12/19
#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap {
	
public:
	// Static members
	const static int MAX_SIZE = 100;
	static int sizecount;

	// Constructors
	Heap();
	~Heap();
	
	// Member functions
	static bool isEmpty();
	char* toString() const;
	static int size();
    static int pop(Node**);
	Node* getRoot();
	
	static void push(Node**, int);
	
private:
	// Private members
	Node* root;
	
	// Private functions
	static void siftUp(Node**, Node*);
	static void siftDown(Node**, Node*);
	
};

#endif