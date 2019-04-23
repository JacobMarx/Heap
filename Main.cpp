// Created by Jacob Marx on 3/12/19
#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"
#include "Heap.h"

void getInput(Node**, Heap*);
bool getInput(Node**, Heap*, char*);
Heap* toHeap(Heap*);
void print(Node**, Heap*);
//void visual(Node**, Node*, Heap*)
void visual(Node*, int);
void print(Node**, Heap*);

int main() {
	Heap* heap = new Heap();
	
	Node** tracker = new Node*[101]; 
	
	for (int i = 0; i <= 100; i++) {
		tracker[i] = NULL;	
	}
	
	// Put input from console or file (between 1 & 1000) into heap
	
	std::cout 
		<< "Would you like to input a file or through the console?"
		<< std::endl;
	char* input;
	std::cin >> input;
	if (strcmp(input, "file") == 0) {
		char* fileName;
		std::cout << "What is the name of the file?" << std::endl;
		std::cin >> fileName;
		getInput(tracker, heap, fileName);
		delete[] fileName;
	}
	else if (strcmp(input, "console") == 0) {
		getInput(tracker, heap);
	}
	
	// Create a menu where they print sorted or tree
	
	// Quit
	std::cout << " " << std::endl;
	std::cout << "Heap size:" << heap->size() << std::endl;
	/*for (int i = 1; i <= heap->size(); i++) {
		if (i % 2 != 0 && tracker[i + 2] == NULL) {
			visual(tracker, heap, tracker[i]);
			std::cout << heap->root->data << std::endl;
		}
	}
	*/
	int depth = 0;
	visual(tracker[1], depth);
	print(tracker, heap);

	return 0;
}

void getInput(Node** tracker, Heap* heap) {
	while (heap->size() <= Heap::MAX_SIZE) {
		int input = 0;
		std::cout << "ghflkfjlj\n";
		std::cin >> input;
		if (input <= 1000 && input >= 1) {
			std::cout << input << std::endl;
			heap->push(tracker, input);
			std::cout << "goon\n";
		}
		//std::cin.unget();
		//std::cout << "Whitespace: " << int(std::cin.get()) << std::endl;
		//std::cin.unget();
		if (std::cin.get() == '\n') {
			std::cout << "hi\n";
			break;
		}
	}
	std::cout << "Left function" << std::endl;
}

bool getInput(Node** tracker, Heap* heap, char* fileName) {
	std::ifstream file;
	file.open(fileName);
	if (file.is_open()) {
		int input = 0;
		while (heap->size() <= Heap::MAX_SIZE) {
			if (file.get() == '\n') {
				break;
			}
			file.unget();
			file >> input;
			if (input <= 1000 && input >= 1) {
				heap->push(tracker, input);
			}
		}
		return true;
	}
	return false;
}

void print(Node** tracker, Heap* heap) {
	while (heap->size() > 0) {
		std::cout << heap->pop(tracker) << " ";
	}
	std::cout << std::endl;
}

/*
void visual (Node** tracker, Node* node, Heap* heap) {
	int counter = 1;
	int tabs = 0;
	while(node != heap->root) {
		for (int i = 1; tracker[i] != node; i++) {
			counter++;
		}
		tabs = ceil(counter/2);
		counter = 0;
		while (counter <= tabs) {
			std::cout << "\t";
		}
		std::cout << tracker[i]->data;
	}
	if (node->left != NULL) {
		visual(tracker, heap, node->left);
	}
	if (node->right != NULL) {
		visual(tracker, heap, node->right);
	}
	visual(tracker, heap, node->parent);
}
*/

void visual(Node* node, int depth) {
	if (node == NULL) return;
	
	visual(node->right, depth + 1);
	
	int count = depth;
	while (count > 0) {
		std::cout << '\t';
		count--;
	}
	std::cout << node->data << std::endl;
	
	visual(node->left, depth + 1);
	
	/*
	int end = 1;
	int counter = 1;
	int endlessLoop = 1;
	while (end <= heap->size()) {
		/*for (counter; counter <= end;) {
			if (tracker[counter] != NULL) {
				//std::cout << tracker[counter]->data << " \\";
				std::cout << " //" << "\\ ";
			}
			else {
				counter++;
				break;
			}
		}
		for (counter; counter <= end;) {
			if (tracker[counter] != NULL) {
				std::cout << tracker[counter]->data << " \\";
				//std::cout << " //" << "\\ ";
			}
			counter++;
			if (endlessLoop != 1) {
				endlessLoop++;
			}
		}
		// bad code but dont have time
		if (endlessLoop == 1) {
			std::cout << std::endl;
			endlessLoop--;
		}
		else {
			break;
		}
		end = (end * 2) + 1;
		if (end > heap->size()) {
			int counter = 0;
			for (int i = 0;; i++) {
				if (tracker[i] != NULL) {
					counter++;
				}
				else {
					break;
				}
			}
			end = counter;
		}
	}
	*/
	
}