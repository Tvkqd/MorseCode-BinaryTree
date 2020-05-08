#include"Header.h"

int main() {
	Morse_Tree myMorse;
	string letters;
	string morseCode;
	//Print out entire Morse tree
	cout << myMorse.full_Morse(myMorse.get_root(), "") << endl;
	
	cout << "Enter a sentence: ";
	getline(cin, letters);
	//Convert letters to morse code
	morseCode = myMorse.letters_to_morse(letters);
	cout << "Convert to morse code" << endl;
	cout << morseCode << endl;
	//Convert morse code to letters
	letters = myMorse.morse_to_letters(morseCode);
	cout << "Convert back to letters" << endl;
	cout << letters << endl;

	system("pause");
	return 0;
}