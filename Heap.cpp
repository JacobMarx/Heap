// Created by Jacob Marx on 3/12/19
#include <cmath>
#include "Node.h"
#include "Heap.h"

Heap::Heap() {
	root = NULL;

}

Heap::~Heap() {
	// do later to lazy
}

bool Heap::isEmpty() const {
	if (sizecount > 0) {
		return false;
	}
	else {
		return true;
	}
}

char* Heap::toString() const {
	return 0;
}

int Heap::size() {
	return sizecount;
}

/*
int ::pop(Node** heap) {
	int curr = 0;
	for (int i = 1;; i++) {
		if (heap[i] == NULL) {
			int swap;
			curr = heap[1]->data;
			swap = heap[i - 1]->data;
			heap[i- 1]->data = root->data;
			root->data = swap;
			//heap[i - 1]->data = curr;
			std::cout << std::endl;
			std::cout << "curr: " << curr << std::endl;
			std::cout << "swap: " << swap << std::endl;
			//delete swap;
			heap[i - 1] = NULL;
			/*if ((i - 1) % 2 != 0) {
				heap[int(floor(i / 2))]->right = NULL;
			}
			else if ((i - 1) % 2 == 0) {
				heap[(i / 2)]->left = NULL;
			}
			*/
			/*
			if (heap[1] != NULL) {
				if (heap[1]->left != NULL || heap[1]->right) {
					siftDown(heap[1]);
				}
			}
			sizecount--;
			break;
		}
	}
	return curr;

}
*/
int Heap::pop(Node** heap) {
	int curr = 0;
	/* Why?
	if (heap[1] != NULL) {
	curr = heap[1]->data;
	}
	*/
	for (int i = 2;; i++) {
		if (heap[i] == NULL) {
			if (i - 1 >= 1) {
				curr = heap[1]->data;
				std::cout << curr << std::endl;
				heap[1]->data = heap[i-1]->data;
				if ((i-1) % 2 != 0) {
					heap[i - 1]->parent->right = NULL;
					heap[i - 1]->parent = NULL;
				}
				else {
					heap[i - 1]->parent->left = NULL;
					heap[i - 1]->parent = NULL;
				}
			}
			else {
				curr = heap[i - 1]->data;
				//std::cout << curr << std::endl;
				heap[i - 1] = NULL;
				sizecount--;
				return curr;
			}
			heap[i - 1] = NULL;
			sizecount--;
			break;
		}
	}
	std::cout << "hi" << std::endl;
	if (heap[1] != NULL) {
		siftDown(heap, heap[1]);
	}
	return curr;
}

void Heap::siftDown(Node** heap, Node* node) {
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
			siftDown(heap, node->left);
		}
	}
	if (node->left == NULL && node->right != NULL) {
		if (node->right->data > node->data) {
			save = node->data;
			node->data = node->right->data;
			node->right->data = save;
			siftDown(heap, node->right);
		}
	}
	if (node->left != NULL && node->left->data > node->data ) {
		save = node->data;
		node->data = node->left->data;
		node->left->data = save;
		siftDown(heap, node->left);
	}
	if (node->right != NULL && node->right->data > node->data) {
		save = node->data;
		node->data = node->right->data;
		node->right->data = save;
		siftDown(heap, node->right);
	}
}

/*
void ::findTarget() {
	// Create array
	int index = 1;
	int* heap;
	// Set index = root
    heap[index] = *(root->data);
	Node* newNode = root;
	// While loop
	while (index-1 < size()) {
		if (newNode->data != NULL) {
			// Left of the node = index*2
			heap[index*2] = *(newNode->left->data);
			// Right of the node = index 2+1
			heap[index*2+1] = *(newNode->left->data);
			index++;
		}
		// Note: Parent = floor(index/2)
	}
	
}
*/

void Heap::push(Node** heap, int in) {
	// If root is null is Null then root->data = int
	// If root doesn't equal Null then add to bottom left to right
	// Then sift up
	// Create Array
	int index = 1;
	Node* newNode = new Node(in);
	sizecount++;
	
	// Set index = root
	//findTarget(heap, root, index);
	
	for (int i = 1;; i++) {
		if (heap[i] == NULL) {
			heap[i] = newNode;
			if (i > 1) {
				newNode->parent = heap[int(i/2)];
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
		siftUp(heap, newNode);
	}
	std::cout << " " << std::endl << in << std::endl << " " << std::endl;
	
}

void Heap::siftUp(Node** heap, Node* node) {
	// If parent node is less than the current node then switch datas
	if (node->parent->data < node->data) {
		int curr = 0;
		curr = node->parent->data;
		node->parent->data = node->data;
		node->data = curr;
		if (node->parent->parent != NULL) {
			siftUp(heap, node->parent);
		}
	}
}

/*
void ::siftDown(Node* node) {
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