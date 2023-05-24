/*
 * Name: Ekaterina (Katy) Kuznetsova
 * Date: May 23, 2023
 * Assignment: Homework 2 Problem 1
 * C++ Version: C++17
 *
 * Program description: This program takes in a series of numbers from the
 * command line and uses three separate threads to calculate a) the average
 * of the series, b) the minimum of the series, and c) the maximum of the
 * series.
 */

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <thread>
using namespace std;

void intro();
bool clientProgram();
void averageCalc();
void getMinValue();
void getMaxValue();

vector<int> digitsFromInput;
double averageValue;
int minimumValue;
int maximumValue;

int main() {

    intro();

    if (clientProgram()) {

        thread th1(averageCalc);

        thread th2(getMinValue);

        thread th3(getMaxValue);

        th1.join();
        th2.join();
        th3.join();

        cout << "The average value is: " << averageValue << endl;
        cout << "The minimum value is: " << minimumValue << endl;
        cout << "The maximum value is: " << maximumValue << endl;
    }


}

void intro(){

    string welcomeMsg = "Welcome to ThreadCalc! Based on the series of numbers"
                    "you enter,\nthis program will calculate the average of"
                    " the series, find the min\nof the series, and find the "
                    "max.\n";

    cout << welcomeMsg;
}

bool clientProgram(){

    //string variable to hold all of user input
    string longInput;

    //string variable to hold a section of string as separated by space
    string inputSection;

    //prompt user to enter a series of numbers
    cout << "Please enter a series of integers separated by spaces:";

    //assign input to string variable
    getline(cin, longInput);

    if (longInput.size()!=0) {

        //create istringstream object copying the contents of string
        istringstream ss(longInput);

        //break up a section of long input and check if it is a digit
        while (getline(ss, inputSection, ' ')) {

            //if it is a digit, put it on the vector
            for (int i = 0; i < inputSection.length(); i++) {
                if (!isdigit(inputSection[i])) {
                    i = inputSection.length();
                }

                if (i == inputSection.length() - 1) {
                    int num = stoi(inputSection);
                    digitsFromInput.push_back(num);
                }
            }
        }

        return 1;

    }
    else {
        cout << "Input was empty. No calculation to do.";
        return 0;
    }
}

void averageCalc(){

    //initialize a sum variable
    int sum = 0;

    //loop through vector to get total sum
    for (int i = 0; i < digitsFromInput.size(); i++){

        //do the addition
        sum += digitsFromInput.at(i);
    }

    //divide by the number of items in vector
    averageValue = sum/digitsFromInput.size();
}

void getMinValue(){

    //initialize the minimum value to the first index
    minimumValue = digitsFromInput.at(0);

    //compare all other indexes to the first and update if a lesser value found
    for (int i = 1; i < digitsFromInput.size(); i++){
        if (minimumValue > digitsFromInput.at(i)){
            minimumValue = digitsFromInput.at(i);
        }
    }
}

void getMaxValue(){

    //initialize the minimum value to the first index
    maximumValue = digitsFromInput.at(0);

    //compare all other indexes to the first and update if a lesser value found
    for (int i = 1; i < digitsFromInput.size(); i++){
        if (maximumValue < digitsFromInput.at(i)){
            maximumValue = digitsFromInput.at(i);
        }
    }
}




