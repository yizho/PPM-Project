#ifndef _IMAGECLASS_H_
#define _IMAGECLASS_H_
#include <iostream>
#include <string>
#include <fstream>
#include "MessageClass.h"

using namespace std;


//Programmer: Yi Zhou
//Date: 03/14/2022
//The imageclass represents a image and related operations

class ImageClass {
    private:
        int maxPixelVal;
        int imageWidth;
        int imageHeight;
        string imageFileType;
        ColorClass* pixelArray;
        //check if input are in valid region
        bool checkRange(int bound, int val) const;

    public:
        //default constructor
        ImageClass();
        ~ImageClass(); //destructor
        
        //new functions for p3
        int getWidth(); //get width value
        int getHeight(); //get height value
        //read ppm file and output array of colorclass
        bool readPpm(
            string fileName
        );
        //write a ppm file
        bool writePpm(
            string fileName
        );
        bool encodeMessage(
            MessageClass &messageToEncode,
            RowColumnClass &upperLeftPos
        );
        int getMin(
            int valueA,
            int valueB
        );
        void decodeImage();
};

#endif