#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

//Programmer: Yi Zhou
//Date: 03/14/2022
//color class defines a pixel

class ColorClass{
    private:
        int redValue;
        int greenValue;
        int blueValue;
        //check if setTo value is in the valid region
        bool checkRange(
            int value
        );
        //sets a color to a value, clips if needed, and avoids duplicated code
        int setToColor(
            int value
        );

    public:
        //added some functions, most functions from p2 unchanged
        //default constructor(full white)
        ColorClass();
        //value constructor
        ColorClass(
            const int inRed,
            const int inGreen,
            const int inBlue
        );
        //set to a specific color
        //3 new for p3
        void setToBlack();
        void setToRed();
        void setToGreen();
        void setToBlue();
        void setToWhite();
        void setToYellow();
        void setToMagenta();
        void setToCyan();
        //sets the color object's RGB values to the provided values
        //returns true if clipping is necessary
        bool setTo (
            const int inRed,
            const int inGreen,
            const int inBlue
        );
        //sets color components to the same as input
        //returns true if clipping is necessary(should always return false)
        bool setTo(
            const ColorClass &inColor
        );
        //causes each RGB value to have the corresponding value 
        //from the input parameter color added to it.
        //returns true if clipping is necessary
        bool addColor(
            const ColorClass &rhsColor
        );
        //similar to add, substract value from RGB values
        //returns true if clipping is necessary
        bool subtractColor(
            const ColorClass &rhsColor
        );
        //performs a simplified brightness adjustment which multiplies 
        //each RGB value by the adjustment factor provided.
        //returns true if clipping is necessary
        bool adjustBrightness(
            const double adjFactor
        );
        //prints the component color values to the console
        void printComponentValues() const;

        //new function for p3
        //read a pixel from ppm to image
        bool readPixelToImage(
            ifstream &inFile 
        );
        //write a pixel from image to ppm
        bool writePixelToPpm(
            ofstream &outFile
        );
        //encode a pixel
        bool encodePixel(
            const int messageValue
        );
        //return true if the number is even
        //return false if odd
        bool isEven(
            const int value
        );
        //encode even/odd
        //avoids code duplication
        void encodeEven(
            int valToEncode
        );
        void encodeOdd(
            int valToEncode
        );

        //encode even/odd
        void encodeRedEven();
        void encodeRedOdd();
        void encodeGreenEven();
        void encodeGreenOdd();
        void encodeBlueEven();
        void encodeBlueOdd();
        
        //decode
        void decodePixel();
};

#endif