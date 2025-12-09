/*
 * Description: This program reads the list of data and shows the list as well as calculates the min, max, and average scores amongst the students.
 *
 * INPUT:
 * 		Constants:
 * 			Number of students = 40
 * 			Number of quizzes = 5
 * 		User input:
 * 			None
 *
 * 	COMPUTATION:
 * 		calculate the average amongst the scores.
 *
 * 	OUTPUT:
 * 		minimum test score, maximum test score, average test score
 *
 * ********************************
 *
 * @author: Blake Dee
 * @contact: blake.dee@my.century.edu
 * @since: 03/23/2025
 *
 * Course: 1081-72
 *
 * Institution: Century College
 *
 * Instructor: Mathew Nyamagwa
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Constants
const int QUIZ_NUM = 5;
const int NUM_STUDENTS = 40;

// Function prototypes
void readData(int nums[][QUIZ_NUM], int studentIDs[], const int QUIZ_NUM, const int NUM_STUDENTS);
void displayData(int nums[][QUIZ_NUM], int studentIDs[], const int QUIZ_NUM, const int NUM_STUDENTS);
void displayStatistics(int nums[][QUIZ_NUM], const int QUIZ_NUM, const int NUM_STUDENTS);

int main() {
    int nums[NUM_STUDENTS][QUIZ_NUM];  // Array to store quiz scores
    int studentIDs[NUM_STUDENTS];  // Array to store student IDs

    cout << "This program reads data for 5 quizzes and gives the min, max, and average scores.\n";

    // Call readData and displayData
    readData(nums, studentIDs, QUIZ_NUM, NUM_STUDENTS);
    displayData(nums, studentIDs, QUIZ_NUM, NUM_STUDENTS);
    displayStatistics(nums, QUIZ_NUM, NUM_STUDENTS);

    return 0;
}

// Function to read data from the file
void readData(int nums[][QUIZ_NUM], int studentIDs[], const int QUIZ_NUM, const int NUM_STUDENTS) {
    ifstream dataFile("scores.md");

    if (!dataFile) {
        cout << "Error opening scores.md. \n";
        return;
    }

    string line;
    // Skip the first line (header)
    getline(dataFile, line);

    // Read the scores into the array, skipping the student ID
    for (int row = 0; row < NUM_STUDENTS; row++) {
        dataFile >> studentIDs[row];  // Read and store the student ID

        for (int col = 0; col < QUIZ_NUM; col++) {
            dataFile >> nums[row][col];  // Read the quiz scores into the array
        }
    }

    dataFile.close();  // Close the file after reading
}

// Function to display the data
void displayData(int nums[][QUIZ_NUM], int studentIDs[], const int QUIZ_NUM, const int NUM_STUDENTS) {
    // Print quiz numbers at the top
    cout << setw(12) << "Student ID";  // Space for Student ID column
    for (int col = 0; col < QUIZ_NUM; col++) {
        cout << setw(8) << "Quiz #" << col + 1;  // Print quiz numbers (Quiz #1, Quiz #2, ...)
    }
    cout << "\n";

    // Print the student IDs and their scores
    for (int row = 0; row < NUM_STUDENTS; row++) {
        cout << setw(12) << studentIDs[row];  // Print the student ID
        for (int col = 0; col < QUIZ_NUM; col++) {
            cout << setw(8) << nums[row][col];  // Print the quiz scores
        }
        cout << "\n";
    }
}

// Function to display the statistics
void displayStatistics(int nums[][QUIZ_NUM], const int QUIZ_NUM, const int NUM_STUDENTS) {
	cout << "===========================================================\n";

	    // Print headers for the statistics row
	    cout << setw(12) << "Statistics";  // Space for Statistic label
	    for (int col = 0; col < QUIZ_NUM; col++) {
	        cout << setw(8) << "Quiz #" << col + 1;  // Print quiz numbers
	    }
	    cout << "\n";

	    // Print the min, max, and avg for each quiz
	    for (int stat = 0; stat < 3; stat++) {  // Loop for min, max, avg
	        cout << setw(12);
	        switch (stat) {
	            case 0: cout << "Min Score"; break;
	            case 1: cout << "Max Score"; break;
	            case 2: cout << "Avg Score"; break;
	        }

	        for (int col = 0; col < QUIZ_NUM; col++) {
	            double minScore = nums[0][col];
	            double maxScore = nums[0][col];
	            double totalScore = 0;

	            // Calculate min, max, and sum for each quiz
	            for (int row = 0; row < NUM_STUDENTS; row++) {
	                if (nums[row][col] < minScore) minScore = nums[row][col];
	                if (nums[row][col] > maxScore) maxScore = nums[row][col];
	                totalScore += nums[row][col];
	            }

	            // Calculate the average score
	            double averageScore = totalScore / NUM_STUDENTS;

	            // Display the statistics for min, max, and avg
	            switch (stat) {
	                case 0:
	                    cout << setw(8) << minScore; break;
	                case 1:
	                    cout << setw(8) << maxScore; break;
	                case 2:
	                    cout << setw(8) << fixed << setprecision(1) << averageScore; break;
	            }
	        }
	        cout << "\n";
	    }
	    cout << "\n\nEND OF PROGRAM!!!";
	}
