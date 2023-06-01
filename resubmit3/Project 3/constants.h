#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Programmer: Yi Zhou
//Date: 03/14/2022
//constantss

//min and max for RGB value
const int MIN_COLOR = 0;
const int MAX_COLOR = 255;

//Menu options
const int ENCODE_IMAGE = 1;
const int DECODE_IMAGE = 2;
const int WRITE_IMAGE = 3;
const int EXIT_PROGRAM = 4;

//exit
const int INCORRECT_NUM_OF_COMMANDS = 2;
const int UNABLE_TO_READ_PPM = 3;

//message values
const int MESSAGE_BLACK = 0;
const int MESSAGE_RED = 1;
const int MESSAGE_GREEN = 2;
const int MESSAGE_BLUE = 3;
const int MESSAGE_WHITE = 4;
const int MESSAGE_YELLOW = 5;
const int MESSAGE_MAGENTA = 6;
const int MESSAGE_CYAN = 7;

//type
const string PPM_TYPE = "P3";

//pixel dimension
const int MAX_DIM = 2000;

//correct number of arguments
const int CORRECT_NUM_ARG = 2;

//index for file name
const int FILE_NAME_IDX = 1;

//row column default
const int DEFAULT_RC_VAL = 0;

#endif