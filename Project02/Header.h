#pragma once
#include<iostream>
#include<string>
#include <sstream>
using namespace std;

//This struct stores information of a node
struct Node {
	char data;
	Node* nextLeft;
	Node* nextRight;
	Node* back;

	//Constructors
	Node() {
		nextLeft = NULL;
		nextRight = NULL;
		back = NULL;
		data = ' ';
	}
};


class Morse_Tree {
	Node* root;
	string morse;
	string alphabet;

public:
	Morse_Tree();

	//Getter
	Node* get_root() { return root; }
	//Print all Morse code
	string full_Morse(Node* temp, string strTemp);

};


