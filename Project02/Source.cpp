#include"Header.h"
#include<fstream>

Morse_Tree::Morse_Tree() {
	Node* currentPosition;
	ifstream morseFile;
	string strTemp;
	int i;

	morseFile.open("morse.txt");

	while (getline(morseFile, strTemp)) {
		currentPosition = root;
		for (i = 1; i < strTemp.length() - 1; i++) {
			//Move left
			if (strTemp[i] == '.') {
				currentPosition = currentPosition->nextLeft;
			}
			//Move right
			if (strTemp[i] == '-') {
				currentPosition = currentPosition->nextRight;
			}
		}
		cout << "Before insert" << endl;
		Node* temp = new Node;
		temp->data = strTemp[0];
		//Insert to the left
		if (strTemp[i] == '.') {
			currentPosition->nextLeft = temp;
		}
		//Insert to the right
		else {
			currentPosition->nextRight = temp;
		}
		temp->back = currentPosition;
	}
}

//Print all Morse code
string Morse_Tree::full_Morse(Node* temp, string strTemp) {
	//Leaf node
	if (temp->nextLeft == NULL && temp->nextRight == NULL) {
		return temp->data + strTemp;
	}
	//Move left
	if (temp->nextLeft != NULL) {
		strTemp += '.';
		return temp->nextLeft->data + strTemp + '\n' + full_Morse(temp->nextLeft, strTemp);
	}
	//Move right
	if (temp->nextRight != NULL) {
		strTemp += '-';
		return temp->nextRight->data + strTemp + '\n' + full_Morse(temp->nextRight, strTemp);
	}
}