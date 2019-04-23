// Created by Jacob Marx on 3/12/19
#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"
#include "Heap.h"

void getInput(Node**);
bool getInput(Node**, char*);
void print(Node**);
void enter(Node**);
void help();
//void visual(Node**, Node*, *)
void visual(Node*, int);
void print(Node**);
char* clear(char*);

int Heap::sizecount = 0;

int main() {
	Node** heap = new Node*[101];
	
	for (int i = 0; i <= 100; i++) {
		heap[i] = NULL;	
	}
	
	int depth = 0;
	bool stop = false;
	
	while (stop == false) {
		//std::cout << "Would you like to input a file or through the console?" << std::endl;
		char* in = new char[20];
		//std::cin >> in;
		if (Heap::isEmpty() == true) {
			std::cout << "You do not have a tree would you like to create one? (yes or no)" << std::endl;
			std::cin >> in;
			if (strcmp(in, "yes") == 0) {
				enter(heap);
				clear(in);
			}
			else if (strcmp(in, "no") == 0) {
				stop = true;
				clear(in);
				break;
			}
			else {
				std::cout << "That was not a valid input" << std::endl;
			}
		}
		else {
			std::cout << "Would you like to 'print', 'list', or 'quit'?" << std::endl;
			std::cin >> in;
			if (strcmp(in, "print") == 0) {
				visual(heap[1], depth);
				clear(in);
			}
			else if (strcmp(in, "quit") == 0) {
				stop = true;
				// Need to delete tree
				break;
			}
			else if (strcmp(in, "list") == 0) {
				print(heap);
				clear(in);
			}
			else {
				std::cout << "You did not enter a valid input. If you would like help enter 'help'." 
				<< std::endl;
				std::cin >> in;
				if (strcmp(in, "help") == 0) {
					help();
					clear(in);
				}
				else {
					continue;
				}
			}
		}
		
	}
	
	
	
	
	/*
	//*  = new ();
	
	Node** heap = new Node*[101];
	
	for (int i = 0; i <= 100; i++) {
		heap[i] = NULL;	
	}
	
	// Put input from console or file (between 1 & 1000) into 
	
	std::cout 
		<< "Would you like to input a file or through the console?"
		<< std::endl;
	char* input = new char[8];
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
	
	int depth = 0;
	visual(heap[1], depth);
	print(heap);
	
	*/
	return 0;
}

void enter(Node** heap) {
	char* input = new char[20];
	std::cout << "Would you like to enter values with a 'file' or 'console'" << std::endl;
	std::cin >> input;
	if (strcmp(input, "file") == 0) {
		char* fileName = new char[80];
		std::cout << "What is the name of the file?" << std::endl;
		std::cin >> fileName;
		getInput(heap, fileName);
		delete[] fileName;
	}
	else if (strcmp(input, "console") == 0) {
		std::cout << "Enter the values you wish to add." << std::endl;
		getInput(heap);
	}
	delete[] input;
}


void help() {
	std::cout << "********************HELP********************" << std::endl 
	<< std::endl << "COMMANDS:" << std::endl 
	<< "\t" << "'list' = Prints tree from greatest to least." << std::endl 
	<< "\t" << "'print' = Visually print the tree." << std::endl 
	<< "\t" << "'quit' = Stops the program." << std::endl << std::endl
	<< "********************************************" << std::endl;
}

void getInput(Node** heap) {
	while (Heap::size() <= Heap::MAX_SIZE) {
		int input = 0;
		//std::cout << "ghflkfjlj\n";
		std::cin >> input;
		if (input <= 1000 && input >= 1) {
			//std::cout << input << std::endl;
			Heap::push(heap, input);
			//std::cout << "goon\n";
		}
		//std::cin.unget();
		//std::cout << "Whitespace: " << int(std::cin.get()) << std::endl;
		//std::cin.unget();
		if (std::cin.get() == '\n') {
			std::cout << "hi\n";
			break;
		}
	}
	//std::cout << "Left function" << std::endl;
}

bool getInput(Node** heap, char* fileName) {
	while (Heap::sizecount <= Heap::MAX_SIZE) {
		std::ifstream file;
		file.open(fileName);
		if (file.is_open()) {
			//char* in = new char[1000];
			char* in = new char[4000];
			int input = 0;
			int index = 0;
			//std::cout << file.get() << std::endl;
			//file.unget();
			file >> in;
			while (true) { // Gage did this
				char current = in[index++];
				if (current == '\0') {
					break;
				} else if (current == ',') {
					Heap::push(heap, input);
					//std::cout << "Input: " << input << std::endl;
					input = 0;
					continue;
				}
				int digit = current - '0';
				input = input * 10 + digit;
			}
			//std::cout << "Input: " << input << std::endl;
			if (input <= 1000 && input >= 1) {
				Heap::push(heap, input);
			}
			return true;
		}
		else {
			std::cout << "There is no file with that name. :(" << std::endl;
		}
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

char* clear(char* arr) {
	for (int i = 0; i <= 20; i++) {
		arr[i] = '\0';
	}
}