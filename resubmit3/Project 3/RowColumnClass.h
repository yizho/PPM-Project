#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//Programmer: Yi Zhou
//Date: 03/14/2022
//ROWCOLUMN Class, defines a row/col position, not often used
//mostly from project2

class RowColumnClass {
    private:
        int indexRow;
        int indexCol;

    public:
        //default constructor
        //most of the functions from p2 unchanged
        RowColumnClass();
        //value constructor
        //sets row and col values to specific values 
        RowColumnClass(
            const int inRow,
            const int inCol
        );
        //set the appropriate attribute(s) to the value(s) provided
        void setRowCol(
            const int inRow,
            const int inCol
        );
        void setRow(
            const int inRow
        );
        void setCol(
            const int inCol
        );
        //return the appropriate attribute value to the caller
        int getRow() const;
        int getCol() const;
        //adds the row and column index values in the input parameter 
        //to the row and column index of the object the function is called on
        void addRowColTo(
            const RowColumnClass &inRowCol
        );
        //prints row and col values
        void printRowCol() const;
};

#endif