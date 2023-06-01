#include <iostream>
#include <string>
#include <fstream>
#include "printChooseMenu.h"
#include "constants.h"
using namespace std;


//Programmer: Yi Zhou
//Date: 03/19/2022
//
//print menu options, check if choice is in range, return choice
//choice must be integer between 1 and 4

int printChooseMenu() {
    bool validInputFound = false;
    int choice;

    cout << "1. Encode a message from file " << endl;
    cout << "2. Perform decode " << endl;
    cout << "3. Write current image to file " << endl;
    cout << "4. Exit the program " << endl;
    cout << "Enter your choice: ";

    while (validInputFound == 0) {
        cin >> choice;
        if (cin.fail() || (choice < ENCODE_IMAGE) || (choice > EXIT_PROGRAM)) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Choice must be int from 1-4! Let's try again!" << endl;
            cout << "Enter your choice: ";
        }
        else {
            validInputFound = true;
        }
    }
    return choice;
}