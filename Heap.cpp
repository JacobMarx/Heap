// Created by Jacob Marx on 3/12/19
#include <cmath>
#include "Node.h"
#include "Heap.h"

Heap::Heap() {
	root = NULL;
	sizecount = 0;

}

Heap::~Heap() {
	// do later to lazy
}

bool Heap::isEmpty() const {
	
	return false;
}

char* Heap::toString() const {
	
	return 0;
}

size_t Heap::size() const {
	
	return sizecount;
}

/*
int Heap::pop(Node** tracker) {
	int curr = 0;
	for (int i = 1;; i++) {
		if (tracker[i] == NULL) {
			int swap;
			curr = tracker[1]->data;
			swap = tracker[i - 1]->data;
			tracker[i- 1]->data = root->data;
			root->data = swap;
			//tracker[i - 1]->data = curr;
			std::cout << std::endl;
			std::cout << "curr: " << curr << std::endl;
			std::cout << "swap: " << swap << std::endl;
			//delete swap;
			tracker[i - 1] = NULL;
			/*if ((i - 1) % 2 != 0) {
				tracker[int(floor(i / 2))]->right = NULL;
			}
			else if ((i - 1) % 2 == 0) {
				tracker[(i / 2)]->left = NULL;
			}
			*/
			/*
			if (tracker[1] != NULL) {
				if (tracker[1]->left != NULL || tracker[1]->right) {
					siftDown(tracker[1]);
				}
			}
			sizecount--;
			break;
		}
	}
	return curr;

}
*/
int Heap::pop(Node** tracker) {
	int curr = 0;
	if (tracker[1] != NULL) {
	curr = tracker[1]->data;
	}
	for (int i = 1;; i++) {
		if (tracker[i] == NULL) {
			if (i - 1 < 1) {
				tracker[1]->data = tracker[i-1]->data;
				if ((i-1) % 2 != 0) {
					tracker[i - 1]->parent->right = NULL;
					tracker[i - 1]->parent = NULL;
				}
				else {
					tracker[i - 1]->parent->left = NULL;
					tracker[i - 1]->parent = NULL;
				}
			}
			else {
				tracker[i - 1] = NULL;
				sizecount--;
				return curr;
			}
			tracker[i - 1] = NULL;
			sizecount--;
			break;
		}
	}
	if (tracker[1] != NULL) {
		siftDown(tracker[1]);
	}
	return curr;
}

void Heap::siftDown(Node* node) {
	// If the right node is not null and the data is greater than the nodes
	// Swap
	// Else if the left node is not null and the data is greater
	// Swap
	/*
	if (node->right != NULL && node->right->data > node->data) {
		int curr = 0;
		curr = node->data;
		node->data = node->right->data;
		node->right->data = curr;
		siftDown(node->right);
	}
	else if (node->left != NULL && node->left->data > node->data) {
		int curr = 0;
		curr = node->data;
		node->data = node->left->data;
		node->left->data = curr;
		siftDown(node->left);
	}
	*/
	int save = 0;
	if (node->left == NULL && node->right == NULL) {
		return;
	}
	if (node->left != NULL && node->right != NULL) {
		if (node->data > node->left->data && node->data > node->right->data /*|| 
				node->left == NULL && node->right == NULL*/) {
			return;
		}
	}
	if (node->right == NULL && node->left != NULL) {
		if (node->left->data > node->data) {
			save = node->data;
			node->data = node->left->data;
			node->left->data = save;
			siftDown(node->left);
		}
	}
	if (node->left == NULL && node->right != NULL) {
		if (node->right->data > node->data) {
			save = node->data;
			node->data = node->right->data;
			node->right->data = save;
			siftDown(node->right);
		}
	}
	if (node->left != NULL && node->left->data > node->data ) {
		save = node->data;
		node->data = node->left->data;
		node->left->data = save;
		siftDown(node->left);
	}
	if (node->right != NULL && node->right->data > node->data) {
		save = node->data;
		node->data = node->right->data;
		node->right->data = save;
		siftDown(node->right);
	}
}

/*
void Heap::findTarget() {
	// Create array
	int index = 1;
	int* tracker;
	// Set index = root
    tracker[index] = *(root->data);
	Node* newNode = root;
	// While loop
	while (index-1 < size()) {
		if (newNode->data != NULL) {
			// Left of the node = index*2
			tracker[index*2] = *(newNode->left->data);
			// Right of the node = index 2+1
			tracker[index*2+1] = *(newNode->left->data);
			index++;
		}
		// Note: Parent = floor(index/2)
	}
	
}
*/

int Heap::findTarget(Node** array, Node* node, int index) {
	//if (node ->left != NULL && node->right != NULL ) {
	if (node != NULL) {
		array[index] = node;
		// Left of the node = index*2
		findTarget(array, node->left, index * 2);
		// Right of the node = index 2+1
		findTarget(array, node->right, index * 2 + 1);
	} 
	else {
		array[index] = NULL;
	}
	/*
	else if (node->left == NULL) {
		return index * 2;
	}
	else if (node->right == NULL) {
		return index * 2 + 1;
	}
	*/
	// Note: Parent = floor(index/2)
}

void Heap::push(Node** tracker, int in) {
	// If root is null is Null then root->data = int
	// If root doesn't equal Null then add to bottom left to right
	// Then sift up
	// Create Array
	int index = 1;
	Node* newNode = new Node(in);
	sizecount ++;
	
	if (root == NULL) {
		root = newNode;
	}
	
	// Set index = root
	//findTarget(tracker, root, index);
	
	for (int i = 1;; i++) {
		if (tracker[i] == NULL) {
			tracker[i] = newNode;
			if (i > 1) {
				newNode->parent = tracker[int(i/2)];
				if (i%2 == 0) {
					newNode->parent->left = newNode;
				}
				else {
					newNode->parent->right = newNode;
				}
			}
			break;
			
		}
	}
	if (newNode->parent != NULL) {
		siftUp(newNode);
	}
	std::cout << " " << std::endl << in << std::endl << " " << std::endl;
	
}

void Heap::siftUp(Node* node) {
	// If parent node is less than the current node then switch datas
	if (node->parent->data < node->data) {
		int curr = 0;
		curr = node->parent->data;
		node->parent->data = node->data;
		node->data = curr;
		if (node->parent->parent != NULL) {
			siftUp(node->parent);
		}
	}
}

/*
void Heap::siftDown(Node* node) {
	// If child node is greater than the current node then switch datas
	if (node->right->data > node->data) {
		int curr = 0;
		curr = node->right->data;
		node->right->data = node->data;
		node->data = curr;
		if (node->left != NULL) {
			siftDown(node->left);
		}
		else if (node->left != NULL) {
			siftDown(node->left);
		}
	}
	else if (node->right->data > node->data) {
		int curr = 0;
		curr = node->right->data;
		node->right->data = node->data;
		node->data = curr;
		if (node->right != NULL) {
			siftDown(node->right);
		}
		else if (node->left != NULL) {
			siftDown(node->left);
		}
	}
	
}
*/