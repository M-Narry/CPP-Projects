/*
 * Description: This program analyzed Cicero I and Cicero II and gives an analysis of the english and latin versions depending on user input.
 *
 *
 * INPUT:
 *		User Input: Option in menus
 *
 *
 * COMPUTATION:
 * 		Calculates the amount of lines, words, characters, and sentences of each file.
 *
 * OUTPUT:
 * 		Lines, words, characters, and sentences of chosen file.
 *
 *************************************
 *
 * @Author: Blake Dee
 * @Contact: blake.dee@my.century.edu
 * @Since: 04/27/2025
 *
 *
 * Course: CSCI 1081-72
 *
 * Institution: Century College
 *
 * Instructor: Mathew Nyamagwa
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Function declarations
void extractText();
void analyzeFile(const string &fileName);
int countLines(const string &fileName);
int countWords(const string &fileName);
int countCharacters(const string &fileName);
int countSentences(const string &fileName);
void displayMenu();

int main() { // Declares functions
	cout << "This program analyzed Cicero I and Cicero II and gives an analysis of the english and latin versions depending on user input.\n";
	extractText();
	displayMenu();

	return 0;
}

void extractText() { // Extracts text from both files
	string inputFiles[] = {"Cicero_I.md", "Cicero_II.md"};
	ofstream latinOut("Cicero_Latin.txt");
	ofstream englishOut("Cicero_English.txt");

	bool headingWrittenLatin = false;
	bool headingWrittenEnglish = false;

	for (int index = 0; index < 2; ++index) {
		ifstream inFile(inputFiles[index]);
		if (!inFile) {
			cerr << "Error opening file: " << inputFiles[index] << "\n";
			continue;
		}

		string line;
		bool isEnglish = false;
		bool headingSeen = false;

		while (getline(inFile, line)) {
			if (!headingSeen && line.find("written by Cicero") != string::npos) {
				// Heading line
				if (!headingWrittenLatin) {
					latinOut << line << "\n\n";
					headingWrittenLatin = true;
				}
				if (!headingWrittenEnglish) {
					englishOut << line << "\n";
					headingWrittenEnglish = true;
				}
				headingSeen = true;
				continue;
			}

			if(line.find("Translation by") != string::npos) {
				//English heading
				if (headingWrittenEnglish) {
					englishOut << line << "\n\n";
				}
				isEnglish = true;
				continue;
			}

			if(line.empty()) continue; // Skips blank lines

			if (isEnglish) {
				englishOut << line << "\n";
			} else {
				latinOut << line << "\n";
			}
		}

		inFile.close();
	}

	latinOut.close();
	englishOut.close();

}

void analyzeFile(const string &fileName) { // Function for analyzing the entire file
	cout << "Showing: " << fileName << "\n"
		 << "Lines: " << countLines(fileName) << "\n"
		 << "Words: " << countWords(fileName) << "\n"
		 << "Characters: " << countCharacters(fileName) << "\n"
		 << "Sentences: " << countSentences(fileName) << "\n"
		 << "--------------------------------------\n";
}

int countLines(const string &fileName) { // Counts the lines of chosen file
	ifstream file(fileName);
	if (!file) {
		cerr << "Error opening file: " << fileName << "\n";
		return 0;
	}

	int lineCount = 0;
	string line;
	while (getline(file, line)) {
		++lineCount;
	}

	file.close();
	return lineCount;
}

int countWords(const string &fileName) { // Counts the words of the chosen file
	ifstream file(fileName);
	if (!file) {
		cerr << "Error opening file: " << fileName << "\n";
		return 0;
	}

	int wordCount = 0;
	string word;
	while (file >> word) {
		++wordCount;
	}

	file.close();
	return wordCount;
}

int countCharacters(const string &fileName) { // Counts the characters of the chosen file
	ifstream file(fileName);
	if (!file) {
		cerr << "Error opening file: " << fileName << "\n";
		return 0;
	}

	int charCount = 0;
	char ch;
	while (file.get(ch)) {
		++charCount;
	}

	file.close();
	return charCount;
}

int countSentences(const string &fileName) { // counts the sentences of the chosen file
	ifstream file(fileName);
	if (!file) {
		cerr << "Error opening file: " << fileName << "\n";
		return 0;
	}

	int sentenceCount = 0;
	char ch;
	while (file.get(ch)) {
		if (ch == '.') {
			++sentenceCount;
		}
	}

	file.close();
	return sentenceCount;
}

void displayMenu() { // Displays the menu for user option
	string fileName;
	int fileChoice;
	int option;

	while (true) {
		cout << "Choose a file to analyze:\n"
			 << "1) Cicero_Latin.txt\n"
			 << "2) Cicero_English.txt\n"
			 << "3) Exit\n"
			 << "Enter your choice: ";
		cin >> fileChoice;

		if (fileChoice == 3) {
			cout << "Exiting program\n";
			break;
		}

		if (fileChoice == 1) {
			fileName = "Cicero_Latin.txt";
		} else if (fileChoice == 2) {
			fileName = "Cicero_English.txt";
		} else {
			cout << "Invalid file choice. Try again.\n\n";
			continue;
		}


		cout << "please select an analysis option:\n"
			 << "1) Line Count\n"
			 << "2) Word Count\n"
			 << "3) Character Count\n"
			 << "4) Sentence Count\n"
			 << "5) All Of The Above\n"
			 << "6) Go back to file menu\n"
			 << "Enter your choice: ";
		cin >> option;

		cout << "\n";

		switch (option) {
		case 1:
			cout << "Lines: " << countLines(fileName) << "\n\n";
			break;
		case 2:
			cout << "Words: " << countWords(fileName) << "\n\n";
			break;
		case 3:
			cout << "Characters: " << countCharacters(fileName) << "\n\n";
			break;
		case 4:
			cout << "Sentences: " << countSentences(fileName) << "\n\n";
			break;
		case 5:
			analyzeFile(fileName);
			break;
		case 6:
			continue;
		default:
			cout << "Invalid option. Try again.\n\n";
		}
	}
}


