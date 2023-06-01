#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "MessageClass.h"
#include "ImageClass.h"

using namespace std;

//Programmer: Yi Zhou
//Date: 03/14/2022
//The imageclass represents a image and related operations
//define ImageClass functions

bool ImageClass::checkRange(int bound, int val) const {
    if ((val >= 0) && (val <= (bound - 1))) {
        return true;
    }
    return false;
}

ImageClass::ImageClass() {
    pixelArray = 0;
}

ImageClass::~ImageClass() {
    delete[] pixelArray;
    pixelArray = 0;
}

//new functions for p3

//getter functions that may help
int ImageClass::getWidth() {
    return imageWidth;
}

int ImageClass::getHeight() {
    return imageHeight;
}

bool ImageClass::readPpm(
    string fileName
) {
    //read
    ifstream inPpmFile;
    inPpmFile.open(fileName.c_str());
    if (inPpmFile.fail()) {
        cout << "ERROR: Open input file failed!" << endl;
        return false;
    }
    //read type
    inPpmFile >> imageFileType;
    if (inPpmFile.eof()) {
        cout << "ERROR: EOF before reading type" << endl;
        return false;
    }
    if ((inPpmFile.fail()) || (imageFileType != PPM_TYPE)) {
        cout << "ERROR: The type of the file is not PPM!" << endl;
        return false;
    }
    //read width
    inPpmFile >> imageWidth;
    if (inPpmFile.eof()) {
        cout << "ERROR: EOF before reading width" << endl;
        return false;
    }
    if ((inPpmFile.fail()) || (imageWidth <= 0) || (imageWidth > MAX_DIM)) {
        cout << "ERROR: Width should be positive integer <= 2000" << endl;
        return false;
    }
    //read height
    inPpmFile >> imageHeight;
    if (inPpmFile.eof()) {
        cout << "ERROR: EOF before reading height" << endl;
        return false;
    }
    if ((inPpmFile.fail()) || (imageHeight <= 0) || (imageHeight > MAX_DIM)) {
        cout << "ERROR: Height should be positive integer <= 2000" << endl;
        return false;
    } 
    //read max pixel value
    inPpmFile >> maxPixelVal;
    if (inPpmFile.eof()) {
        cout << "ERROR: EOF before reading max pixel value" << endl;
        return false;
    }
    if ((inPpmFile.fail()) || (maxPixelVal != MAX_COLOR)) {
        cout << "ERROR: Max number of RGB values must be 255!";
        return false;
    }

    //read to array
    pixelArray = new ColorClass[imageWidth * imageHeight];
    int tempIndex;
    string temp;
    while (!inPpmFile.eof()) {
        for (int i = 0; i < imageHeight; i++) {
            for (int j = 0; j < imageWidth; j++) {
                tempIndex = i * imageWidth + j;
                if (!pixelArray[tempIndex].readPixelToImage(inPpmFile)) {
                    
                    cout << "Error: Reading color from file" << endl;
                    cout << "Error: Reading image pixel at row: ";
                    cout << i << " col: " << j << endl;
                    return false;
                }
            }
        }
        //if can read more, then something's wrong
        inPpmFile >> temp;
        if (temp != "") {
            cout << "ERROR: Number of values must match image size!" << endl;
            return false;
        }
    }
    inPpmFile.close();
    return true;
}

//write ppm file
bool ImageClass::writePpm(
    string fileName
) {
    
    ofstream outPpmFile;
    outPpmFile.open(fileName.c_str());
    if (outPpmFile.fail()) {
        cout << "ERROR: Fail to open output file!" << endl;
        return false;
    }
    //the first three lines
    outPpmFile << imageFileType << endl;
    outPpmFile << imageWidth << " " << imageHeight << endl;
    outPpmFile << maxPixelVal << endl;
    //write each pixel
    int tempIndex;
    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            tempIndex = i * imageWidth + j;
            if (!pixelArray[tempIndex].writePixelToPpm(outPpmFile)) {
                cout << "Error: Writing color from file" << endl;
                cout << "Error: Writing image pixel at row: ";
                cout << i << " col: " << j << endl;
                return false;
            }
        }
    }
    outPpmFile << endl;
    outPpmFile.close();
    return true;

}

//encode message

bool ImageClass::encodeMessage(
    MessageClass &messageToEncode,
    RowColumnClass &upperLeftPos
) {
    //get position
    int rowPosition = upperLeftPos.getRow();
    int colPosition = upperLeftPos.getCol();
    //get matrix
    int** messageArray = messageToEncode.getMessageArray();
    //get width/height
    int messageWidth = messageToEncode.getWidth();
    int messageHeight = messageToEncode.getHeight();
    //real width/height
    int realWidth = getMin(colPosition + messageWidth, imageWidth);
    int realHeight = getMin(rowPosition + messageHeight, imageHeight);

    //completely out of image
    if ((colPosition >= imageWidth) || (rowPosition >= imageHeight)) {
        return true;
    }

    if ((realWidth < 0) || (realHeight < 0)) {
        return true;
    }

    //encode each pixel
    int tempIndex;
    int valToEncode;
    for (int i = rowPosition; i < realHeight; i++) {
        for (int j = colPosition; j < realWidth; j++) {
            //only encode if i,j >= 0
            if ((i >= 0) && (j >= 0)) {
                valToEncode = messageArray[i - rowPosition][j - colPosition];
                tempIndex = i * imageWidth + j;
                if (!pixelArray[tempIndex].encodePixel(valToEncode)) {
                    cout << "Error: encode failure." << endl;
                    return false;
                }
            }
            
        }
    }
    return true;  
}

int ImageClass::getMin(
    int valueA,
    int valueB
) {
    if (valueA > valueB) {
        return valueB;
    }
    return valueA;
}

void ImageClass::decodeImage() {
    //go thru array to decode pixel
    int tempIndex;
    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            tempIndex = i * imageWidth + j;
            pixelArray[tempIndex].decodePixel();
        }
    }
    return;
}