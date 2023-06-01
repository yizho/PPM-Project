#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "MessageClass.h"


using namespace std;


//Programmer: Yi Zhou
//Date: 03/21/2022
//MessageClass: defines a message and reads message
//defines MessageClass functions

int MessageClass::getWidth() {
    return messageWidth;
}

int MessageClass::getHeight() {
    return messageHeight;
}

int** MessageClass::getMessageArray() {
    return messageArray;
}

MessageClass::MessageClass() {
    messageArray = 0;
}

MessageClass::~MessageClass() {
    delete[] messageArray;
    messageArray = 0;
}


bool MessageClass::readMessage(
    string fileName
) {
    //read
    ifstream inTxtFile;
    inTxtFile.open(fileName.c_str());
    if (inTxtFile.fail()) {
        cout << "ERROR: Open input message file failed!" << endl;
        return false;
    }
    //read width and height
    inTxtFile >> messageWidth;
    if (inTxtFile.eof()) {
        cout << "ERROR: EOF before reading width" << endl;
        return false;
    }
    if ((inTxtFile.fail()) || (messageWidth <= 0)) {
        cout << "ERROR: Width should be positive integer" << endl;
        return false;
    }
    inTxtFile >> messageHeight;
    if (inTxtFile.eof()) {
        cout << "ERROR: EOF before reading height" << endl;
        return false;
    }
    if ((inTxtFile.fail()) || (messageHeight <= 0)) {
        cout << "ERROR: Height should be positive integer" << endl;
        return false;
    }
    //matrix
    messageArray = new int* [messageHeight];
    for (int i = 0; i < messageHeight; i++) {
        messageArray[i] = new int [messageWidth];
    }
    //go thru the matrix to store
    string temp;
    while (!inTxtFile.eof()) {
        for (int i = 0; i < messageHeight; i++) {
            for (int j = 0; j < messageWidth; j++) {
                inTxtFile >> messageArray[i][j];
                if (inTxtFile.eof()) {
                    cout << "ERROR: EOF before reading message value" << endl;
                    return false;
                }
                if (inTxtFile.fail()) {
                    cout << "Error: Reading message value at row/col: ";
                    cout << i << " " << j << endl;
                    return false;
                }
                if ((messageArray[i][j] < 0) || (messageArray[i][j] > 7)) {
                    cout << "Error: invalid message value." << endl;
                    cout << "Error: Reading message value at row/col: ";
                    cout << i << " " << j << endl;
                    return false;
                }
            }
        }
        //if can read more, then something's wrong
        inTxtFile >> temp;
        if (temp != "") {
            cout << "ERROR: Number of values must match message size!" << endl;
            return false;
        }
    }
    inTxtFile.close();
    return true;
}