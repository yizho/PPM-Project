#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "ColorClass.h"

using namespace std;

//Programmer: Yi Zhou
//Date: 03/14/2022
//color class defines a pixel
//define ColorClass functions

bool ColorClass::checkRange(
    int value
) {
    if ((value < MIN_COLOR) || (value > MAX_COLOR)) {
        return false;
    }
    return true;
}

int ColorClass::setToColor(
    int value
) {
    int resultVal;
    if (checkRange(value)) {
        resultVal = value;
    } else if (value < MIN_COLOR) {
        resultVal = MIN_COLOR;
    } else {
        resultVal = MAX_COLOR;
    }
    return resultVal;
}

ColorClass::ColorClass() {
    //all max
    redValue = MAX_COLOR; 
    greenValue = MAX_COLOR; 
    blueValue = MAX_COLOR;
}

ColorClass::ColorClass(
    const int inRed,
    const int inGreen,
    const int inBlue
) {
    redValue = setToColor(inRed); 
    greenValue = setToColor(inGreen); 
    blueValue = setToColor(inBlue);
}

void ColorClass::setToBlack() {
    //all min
    redValue = MIN_COLOR; 
    greenValue = MIN_COLOR; 
    blueValue = MIN_COLOR;
}

void ColorClass::setToRed() {
    redValue = MAX_COLOR; 
    greenValue = MIN_COLOR; 
    blueValue = MIN_COLOR;
}

void ColorClass::setToGreen() {
    redValue = MIN_COLOR; 
    greenValue = MAX_COLOR; 
    blueValue = MIN_COLOR;
}

void ColorClass::setToBlue() {
    redValue = MIN_COLOR; 
    greenValue = MIN_COLOR; 
    blueValue = MAX_COLOR;
}

void ColorClass::setToWhite() {
    redValue = MAX_COLOR; 
    greenValue = MAX_COLOR; 
    blueValue = MAX_COLOR;
}

void ColorClass::setToYellow() {
    redValue = MAX_COLOR; 
    greenValue = MAX_COLOR; 
    blueValue = MIN_COLOR;
}

void ColorClass::setToMagenta() {
    redValue = MAX_COLOR; 
    greenValue = MIN_COLOR; 
    blueValue = MAX_COLOR;
}

void ColorClass::setToCyan() {
    redValue = MIN_COLOR; 
    greenValue = MAX_COLOR; 
    blueValue = MAX_COLOR;
}

bool ColorClass::setTo (
    const int inRed,
    const int inGreen,
    const int inBlue
) {
    redValue = setToColor(inRed); 
    greenValue = setToColor(inGreen); 
    blueValue = setToColor(inBlue);
    //check if clipping is needed
    if (checkRange(inRed) && checkRange(inGreen) && checkRange(inBlue)) {
        return false;
    }
    return true;
}

bool ColorClass::setTo(
    const ColorClass &inColor
) {
    redValue = inColor.redValue; 
    greenValue = inColor.greenValue; 
    blueValue = inColor.blueValue;
    return false;
}

bool ColorClass::addColor(
    const ColorClass &rhsColor
) {
    bool tempCheck;//checks if needs clipping
    tempCheck = setTo(
        int (redValue + rhsColor.redValue),
        int (greenValue + rhsColor.greenValue),
        int (blueValue + rhsColor.blueValue)
    );
    return tempCheck;
}

bool ColorClass::subtractColor(
    const ColorClass &rhsColor
) {
    bool tempCheck;//checks if needs clipping
    tempCheck = setTo(
        int (redValue - rhsColor.redValue),
        int (greenValue - rhsColor.greenValue),
        int (blueValue - rhsColor.blueValue)
    );
    return tempCheck;
}

bool ColorClass::adjustBrightness(
    const double adjFactor
) {
    bool tempCheck;//checks if needs clipping
    tempCheck = setTo(
        int (redValue * adjFactor),
        int (greenValue * adjFactor),
        int (blueValue * adjFactor)
    );
    return tempCheck;
}

void ColorClass::printComponentValues() const {
    cout << "R: " << redValue
         << " G: " << greenValue
         << " B: " << blueValue;
}

bool ColorClass::readPixelToImage(
    ifstream &inFile
) {
    //read
    inFile >> redValue >> greenValue >> blueValue;
    if (inFile.eof()) {
        cout << "ERROR: EOF when reading RGB" << endl;
        return false;
    }
    if (inFile.fail()) {
        return false;
    }
    //check if RGB input is valid
    if (!checkRange(redValue) || !checkRange(greenValue) || 
    !checkRange(blueValue)) {
        cout << "ERROR: Pixel has invalid RGB values." << endl;
        return false;
    }
    return true;
}

bool ColorClass::writePixelToPpm(
    ofstream &outFile
) {
    outFile << redValue << " " << greenValue << " " << blueValue << " ";
    if (outFile.fail()) {
        return false;
    }
    return true;
}

bool ColorClass::encodePixel(
    const int messageValue
) {
    if (messageValue == MESSAGE_BLACK) {
        encodeRedEven();
        encodeGreenEven();
        encodeBlueEven();
    }
    else if (messageValue == MESSAGE_RED) {
        encodeRedOdd();
        encodeGreenEven();
        encodeBlueEven();
    }
    else if (messageValue == MESSAGE_GREEN) {
        encodeRedEven();
        encodeGreenOdd();
        encodeBlueEven();
    }
    else if (messageValue == MESSAGE_BLUE) {
        encodeRedEven();
        encodeGreenEven();
        encodeBlueOdd();
    }
    else if (messageValue == MESSAGE_WHITE) {
        encodeRedOdd();
        encodeGreenOdd();
        encodeBlueOdd();
    }
    else if (messageValue == MESSAGE_YELLOW) {
        encodeRedOdd();
        encodeGreenOdd();
        encodeBlueEven();
    }
    else if (messageValue == MESSAGE_MAGENTA) {
        encodeRedOdd();
        encodeGreenEven();
        encodeBlueOdd();
    }
    else if (messageValue == MESSAGE_CYAN) {
        encodeRedEven();
        encodeGreenOdd();
        encodeBlueOdd();
    }
    else {
        cout << "Error: Message value must be integer from 0-7." << endl;
        return false;
    }
    return true;
}

bool ColorClass::isEven(
    const int value
) {
    if (value % 2 == 0) {
        return true;
    }
    return false;
}

void ColorClass::encodeEven(
    int valToEncode
) {
    if (!isEven(valToEncode)) {
        valToEncode--;
    }
    return;
}

void ColorClass::encodeOdd(
    int valToEncode
) {
    if (isEven(valToEncode)) {
        valToEncode++;
    }
    return;
} 

void ColorClass::encodeRedEven() {
    if (!isEven(redValue)) {
        redValue--;
    }
}

void ColorClass::encodeRedOdd() {
    if (isEven(redValue)) {
        redValue++;
    }
}

void ColorClass::encodeGreenEven() {
    if (!isEven(greenValue)) {
        greenValue--;
    }
}

void ColorClass::encodeGreenOdd() {
    if (isEven(greenValue)) {
        greenValue++;
    }
}

void ColorClass::encodeBlueEven() {
    if (!isEven(blueValue)) {
        blueValue--;
    }
}

void ColorClass::encodeBlueOdd() {
    if (isEven(blueValue)) {
        blueValue++;
    }
}

void ColorClass::decodePixel() {
    if (isEven(redValue)) {
        //
        if (isEven(greenValue)) {
            //
            if (isEven(blueValue)) {
                //even even even
                setToBlack();
            }
            else if (!isEven(blueValue)) {
                //even even odd
                setToBlue();
            }
        }
        else if (!isEven(greenValue)) {
            //
            if (isEven(blueValue)) {
                //even odd even
                setToGreen();
            }
            else if (!isEven(blueValue)) {
                //even odd odd
                setToCyan();
            }
        }
    }
    else if (!isEven(redValue)) {
        //
        if (isEven(greenValue)) {
            //
            if (isEven(blueValue)) {
                //odd even even
                setToRed();
            }
            else if (!isEven(blueValue)) {
                //odd even odd
                setToMagenta();
            }
        }
        else if (!isEven(greenValue)) {
            //
            if (isEven(blueValue)) {
                //odd odd even
                setToYellow();
            }
            else if (!isEven(blueValue)) {
                //odd odd odd
                setToWhite();
            }
        }
    }
}