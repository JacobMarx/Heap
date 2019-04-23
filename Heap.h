// Created by Jacob Marx on 3/12/19
#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap {
	
public:
	// Static members
	const static int MAX_SIZE = 100;
	int sizecount;

	// Constructors
	Heap();
	~Heap();
	
	// Member functions
	bool isEmpty() const;
	char* toString() const;
	size_t size() const;
    int pop(Node**);
	
	void push(Node**, int);
	
private:
	// Private members
	
	Node* root;
	Node* target;
	
	// Private functions
	void siftUp(Node*);
	void siftDown(Node*);
	int findTarget(Node**, Node*, int);
	
	
};

#endif