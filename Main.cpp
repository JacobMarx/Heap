// Created by Jacob Marx on 3/12/19
#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"
#include "Heap.h"

void getInput(Node**);
bool getInput(Node**, char*);
void print(Node**);
//void visual(Node**, Node*, *)
void visual(Node*, int);
void print(Node**);

int Heap::sizecount = 0;

int main() {
	//*  = new ();
	
	Node** heap = new Node*[101];
	
	for (int i = 0; i <= 100; i++) {
		heap[i] = NULL;	
	}
	
	// Put input from console or file (between 1 & 1000) into 
	
	std::cout 
		<< "Would you like to input a file or through the console?"
		<< std::endl;
	char* input;
	std::cin >> input;
	if (strcmp(input, "file") == 0) {
		char* fileName;
		std::cout << "What is the name of the file?" << std::endl;
		std::cin >> fileName;
		getInput(heap, fileName);
		delete[] fileName;
	}
	else if (strcmp(input, "console") == 0) {
		getInput(heap);
	}
	
	// Create a menu where they print sorted or tree
	
	// Quit
	std::cout << " " << std::endl;
	std::cout << " size:" << Heap::size() << std::endl;
	/*for (int i = 1; i <= ->size(); i++) {
		if (i % 2 != 0 && heap[i + 2] == NULL) {
			visual(heap, , heap[i]);
			std::cout << ->root->data << std::endl;
		}
	}
	*/
	int depth = 0;
	visual(heap[1], depth);
	print(heap);

	return 0;
}

void getInput(Node** heap) {
	while (Heap::size() <= Heap::MAX_SIZE) {
		int input = 0;
		std::cout << "ghflkfjlj\n";
		std::cin >> input;
		if (input <= 1000 && input >= 1) {
			std::cout << input << std::endl;
			Heap::push(heap, input);
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

bool getInput(Node** heap, char* fileName) {
	std::ifstream file;
	file.open(fileName);
	if (file.is_open()) {
		int input = 0;
		while (Heap::size() <= Heap::MAX_SIZE) {
			if (file.get() == '\n') {
				break;
			}
			file.unget();
			file >> input;
			if (input <= 1000 && input >= 1) {
				Heap::push(heap, input);
			}
		}
		return true;
	}
	return false;
}

void print(Node** heap) {
	while (Heap::size() > 0) {
		std::cout << Heap::pop(heap) << " ";
	}
	std::cout << std::endl;
}

/*
void visual (Node** heap, Node* node, * ) {
	int counter = 1;
	int tabs = 0;
	while(node != ->root) {
		for (int i = 1; heap[i] != node; i++) {
			counter++;
		}
		tabs = ceil(counter/2);
		counter = 0;
		while (counter <= tabs) {
			std::cout << "\t";
		}
		std::cout << heap[i]->data;
	}
	if (node->left != NULL) {
		visual(heap, , node->left);
	}
	if (node->right != NULL) {
		visual(heap, , node->right);
	}
	visual(heap, , node->parent);
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
	while (end <= ->size()) {
		/*for (counter; counter <= end;) {
			if (heap[counter] != NULL) {
				//std::cout << heap[counter]->data << " \\";
				std::cout << " //" << "\\ ";
			}
			else {
				counter++;
				break;
			}
		}
		for (counter; counter <= end;) {
			if (heap[counter] != NULL) {
				std::cout << heap[counter]->data << " \\";
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
		if (end > ->size()) {
			int counter = 0;
			for (int i = 0;; i++) {
				if (heap[i] != NULL) {
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