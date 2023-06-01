#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ImageClass.h"
#include "MessageClass.h"
#include "printChooseMenu.h"
#include "constants.h"

using namespace std;

//Programmer: Yi Zhou
//Date: 03/21/2022
//This program encodes and decodes ppm files.
//It can also read and write valid ppm files.

//I did not submit by the original due date. 
//This resubmission would be my first submission.


int main(int argc, char *argv[]) {
    if (argc != CORRECT_NUM_ARG) {
        cout << "Usage: ./project3.exe <startPPM.ppm>" << endl;
        exit(INCORRECT_NUM_OF_COMMANDS);
    }
    string programInFileName = argv[FILE_NAME_IDX];
    cout << "Reading initial image from: " << programInFileName << endl;
    //store input image
    ImageClass image;
    if (!image.readPpm(programInFileName)) {
        cout << "Image read successful: No" << endl;
        cout << "Error: While reading the image, an error was";
        cout << " encountered.  Exiting the program!" << endl;
        exit(UNABLE_TO_READ_PPM);
    }
    else {
        cout << "Image read successful: Yes" << endl;
    }
    int userChoice = 0;
    while (userChoice != EXIT_PROGRAM) {
        userChoice = printChooseMenu();
        //user choose to write image
        if (userChoice == WRITE_IMAGE) {
            string programOutFileName;
            cout << "Enter name of file to write image to: ";
            cin >> programOutFileName;
            if (image.writePpm(programOutFileName)) {
                cout << "Image write successful: Yes" << endl;
            }
            else {
                cout << "Image write successful: No" << endl;
            }
        }
        //user choose to encode
        if (userChoice == ENCODE_IMAGE) {
            string messageFileName;
            cout << "Enter name of file containing message: ";
            cin >> messageFileName;
            cout << "Enter row and column for message placement: ";
            RowColumnClass position;
            bool validRowInputFound = 0;
            //cin the row and column
            int rowVal;
            while (validRowInputFound == 0) {
                cin >> rowVal;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(200, '\n');
                    cout << "ROW/COL must be integer! Try again!" << endl;
                    cout << "Enter row and column for message placement: ";
                }
                else {
                    validRowInputFound = 1;
                }
            }
            bool validColInputFound = 0;
            int colVal;
            while (validColInputFound == 0) {
                cin >> colVal;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(200, '\n');
                    cout << "ROW/COL must be integer! Try again!" << endl;
                    cout << "Enter row and column for message placement: ";
                }
                else {
                    validColInputFound = 1;
                }
            }
            position.setRow(rowVal);
            position.setCol(colVal);
            //now read message
            MessageClass message;
            if (!message.readMessage(messageFileName)) {
                cout << "Message encode successful: No" << endl;
            }
            else {
                if (image.encodeMessage(message, position)) {
                    cout << "Message encode successful: Yes" << endl;
                }
                else {
                    cout << "Message encode successful: No" << endl;
                }
            }
        }
        //user choose to decode
        if (userChoice == DECODE_IMAGE) {
            image.decodeImage();
            cout << "Image modified to decoded image contents" << endl;
        }

    }
    //user choose to exit
    cout << "Thanks for using this program!" << endl;
    return 0;


}