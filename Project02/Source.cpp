#include"Header.h"
#include<fstream>

Morse_Tree::Morse_Tree() {
	Node* rootNode = new Node;
	root = rootNode;
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
	morseFile.close();
	cout << "Morse Tree is ready\n";
}

//Print all Morse code
string Morse_Tree::full_Morse(Node* rootTemp, string strTemp) {

	if (rootTemp->nextLeft != NULL) {
		//Move left
		cout << full_Morse(rootTemp->nextLeft, strTemp + '.') << endl;
	}
	
	if (rootTemp->nextRight != NULL) {
		//Move right
		cout << full_Morse(rootTemp->nextRight, strTemp + '-') << endl;
	}
	return rootTemp->data + strTemp;
}

//Find morse code of a letter
string Morse_Tree::find(Node* rootTemp, string strTemp, char letter) {
	string result = "NA";

	if (rootTemp->nextLeft != NULL) {
		//Move left
		if (rootTemp->nextLeft->data == letter)
			result =  strTemp + '.';
		else
			result = find(rootTemp->nextLeft, strTemp + '.', letter);
	}

	if (rootTemp->nextRight != NULL && result == "NA") {
		//Move right
		if (rootTemp->nextRight->data == letter)
			result = strTemp + '-';
		else
			result = find(rootTemp->nextRight, strTemp + '-', letter);
	}
	return result;
}

//Convert letters to morse code
string Morse_Tree::letters_to_morse(string letters) {
	string result = "";

	for (int i = 0; i < letters.length(); i++) {
		//Convert each letter to morse code
		if (isalpha(letters[i])) {
			result += find(root, "", tolower(letters[i]));
			result += '/';
		}
		else
			result += "\t";
	}
	return result;
}

//Convert morse code to letters
string Morse_Tree::morse_to_letters(string morseCode) {
	string result;
	Node* temp = root;

	for (int i = 0; i < morseCode.length(); i++) {
		//Move left
		if (morseCode[i] == '.') {
			temp = temp->nextLeft;
		}
		//Move right
		else if (morseCode[i] == '-') {
			temp = temp->nextRight;
		}
		//Finish 1 word
		else if (morseCode[i] == ' ') {
			result += morseCode[i];
		}
		//Start new letter
		else {
			result += temp->data;
			temp = root;
		}
	}
	return result;
}
