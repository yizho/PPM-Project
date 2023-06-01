#ifndef _MESSAGECLASS_H_
#define _MESSAGECLASS_H_
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Programmer: Yi Zhou
//Date: 03/21/2022
//Message Class: defines a message and reads message

class MessageClass {
    private:
    int messageWidth;
    int messageHeight;
    int** messageArray;

    public:
    MessageClass();
    ~MessageClass();//destructor
    //getters
    int getWidth();
    int getHeight();
    int** getMessageArray();
    //read message
    bool readMessage(
        string fileName
    );

};

#endif
