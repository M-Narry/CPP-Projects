/*
 * Description: This program provides a report of a given student's scores, average, or grade
 * as well as all data, and a list of student IDs and names based on inquiry.
 *
 *
 * INPUT:
 * 		Constants:
 * 			Class size = 40
 * 		User Input:
 * 			Menu option
 * 			Student ID number
 *
 *
 * COMPUTATION:
 * 		Calculate student's average
 * 		Calculate student's letter grade
 *
 * OUTPUT:
 * 		Student's quiz scores, letter grade, average scores
 * 		List of students and their ID numbers
 *
 *********************************************************
 *
 *	@author: Blake Dee
 *	@contact: blake.dee@my.century.edu
 *	@since: 04/13/2025
 *
 *
 *	Course: CSCI 1081-72
 *
 *	Institution: Century College
 *
 *	Instructor: Mathew Nyamagwa
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int studentId;
    double quiz1;
    double quiz2;
    double quiz3;
    double quiz4;
    double examScore;
};

// Function prototypes
bool isInteger(const string &s);
bool isNumber(const string &s);
void readData(Student students[], int &count, const string &fileName);
double calculateAverage(const Student &s);
char determineGrade(double avg);
void displayScores(const Student &s);
void displayStudentData(const Student &s);
void displayData(const Student students[], int count);
void menu(Student students[], int count);

const int MAX_SIZE = 40;

// Utility functions to help read the data
bool isInteger(const string &s) {
    if (s.empty()) return false;
    for (int index = 0; index < int(s.length()); index++)
        if (!isdigit(s[index])) return false;
    return true;
}

bool isNumber(const string &s) {
    if (s.empty()) return false;
    int dots = 0;
    for (int index = 0; index < int(s.length()); index++) {
        if (s[index] == '.') {
            dots++;
            if (dots > 1) return false;
        } else if (!isdigit(s[index])) return false;
    }
    return true;
}

// Reads the file data
void readData(Student students[], int &count, const string &fileName) {
    ifstream dataFile(fileName);
    if (!dataFile) {
        cerr << "Error: Unable to open file.\n";
        return;
    }

    dataFile.ignore(1000, '\n'); // Skip header
    string line;
    count = 0;

    while (getline(dataFile, line) && count < MAX_SIZE) {
        if (line.empty()) continue;

        string parts[15], temp = "";
        int partIndex = 0;
        bool inWord = false;

        for (int index = 0; index < int(line.length()); index++) {
            char ch = line[index];
            if (ch != ' ' && ch != '\t') {
                temp += ch;
                inWord = true;
            } else if (inWord) {
                parts[partIndex++] = temp;
                temp = "";
                inWord = false;
            }
        }
        if (!temp.empty()) parts[partIndex++] = temp;
        if (partIndex < 7) continue;

        int last = partIndex - 1;
        if (!isNumber(parts[last]) || !isNumber(parts[last - 1]) ||
            !isNumber(parts[last - 2]) || !isNumber(parts[last - 3]) ||
            !isNumber(parts[last - 4]) || !isInteger(parts[last - 5])) continue;

        students[count].examScore = stod(parts[last]);
        students[count].quiz4 = stod(parts[last - 1]);
        students[count].quiz3 = stod(parts[last - 2]);
        students[count].quiz2 = stod(parts[last - 3]);
        students[count].quiz1 = stod(parts[last - 4]);
        students[count].studentId = stoi(parts[last - 5]);

        string name = parts[0];
        for (int index = 1; index <= last - 6; index++) name += " " + parts[index];
        students[count].name = name;

        count++;
    }

    dataFile.close();
}

// Calculates average score
double calculateAverage(const Student &s) {
    return (s.quiz1 + s.quiz2 + s.quiz3 + s.quiz4 + s.examScore) / 5.0;
}

// Determines student's letter grade
char determineGrade(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

// Displays individual student scores
void displayScores(const Student &s) {
    cout << "Scores for " << s.name << ":\n";
    cout << "Quiz 1: " << s.quiz1 << "\nQuiz 2: " << s.quiz2
         << "\nQuiz 3: " << s.quiz3 << "\nQuiz 4: " << s.quiz4
         << "\nExam: " << s.examScore << "\n\n";
}

// Displays individual student data
void displayStudentData(const Student &s) {
    double avg = calculateAverage(s);
    cout << "Student Name: " << s.name << "\n"
         << "Student ID: " << s.studentId << "\n"
         << "Quiz #1: " << s.quiz1 << "\n"
         << "Quiz #2: " << s.quiz2 << "\n"
         << "Quiz #3: " << s.quiz3 << "\n"
         << "Quiz #4: " << s.quiz4 << "\n"
         << "Exam: " << s.examScore << "\n"
         << "Average: " << fixed << setprecision(2) << avg << "\n"
         << "Grade: " << determineGrade(avg) << "\n\n";
}
// Displays the data for all of the students
void displayData(const Student students[], int count) {
    for (int index = 0; index < count; index++)
        cout << "ID: " << students[index].studentId << " | Name: " << students[index].name << "\n";
    cout << endl;
}

// A nice little menu
void menu(Student students[], int count) {
    int selection, searchId;

    do {
        cout << "\nPlease select option:\n"
             << "1. Find Student's scores\n"
             << "2. Find student's average scores\n"
             << "3. Find Student's grade\n"
             << "4. Provide data for a given student\n"
             << "5. Full list of student IDs and names\n"
             << "6. Exit\n"
             << "Enter choice: ";
        cin >> selection;

        if (selection >= 1 && selection <= 4) {
            cout << "Enter Student ID: ";
            cin >> searchId;

            int foundIndex = -1;
            for (int i = 0; i < count; i++) {
                if (students[i].studentId == searchId) {
                    foundIndex = i;
                    break;
                }
            }

            if (foundIndex == -1) {
                cout << "Student ID not found.\n";
                continue;
            }

            const Student &s = students[foundIndex];
            switch (selection) {
                case 1: displayScores(s); break;
                case 2: cout << "Average for " << s.name << ": "
                             << fixed << setprecision(2) << calculateAverage(s) << "\n\n"; break;
                case 3: cout << "Grade for " << s.name << ": "
                             << determineGrade(calculateAverage(s)) << "\n\n"; break;
                case 4: displayStudentData(s); break;
            }
        } else if (selection == 5) {
            displayData(students, count);
        } else if (selection != 6) {
            cout << "Invalid input! Please select a valid menu option.\n";
        }

    } while (selection != 6);
}
// Introduces program and calls functions
int main() {
	cout << "This program provides a report of a given student's scores, average, or \n"
		 <<	"grade as well as all data on that student.\n "
		 <<	"It also provides a list of student IDs and names based on inquiry.\n";
    Student students[MAX_SIZE];
    int studentCount = 0;
    readData(students, studentCount, "Students Record.md");
    menu(students, studentCount);
    return 0;
}
