#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "RowColumnClass.h"

using namespace std;


//Programmer: Yi Zhou
//Date: 03/14/2022
//ROWCOLUMN Class
//define RowColumnClass functions

RowColumnClass::RowColumnClass() {
    indexRow = DEFAULT_RC_VAL;
    indexCol = DEFAULT_RC_VAL;
}

RowColumnClass::RowColumnClass(
    const int inRow, 
    const int inCol
) {
    indexRow = inRow;
    indexCol = inCol;
}

void RowColumnClass::setRowCol(
    const int inRow,
    const int inCol
) {
    setRow(inRow);
    setCol(inCol);
}

void RowColumnClass::setRow(
    const int inRow
) {
    indexRow = inRow;
}

void RowColumnClass::setCol(
    const int inCol
) {
    indexCol = inCol;
}

int RowColumnClass::getRow() const {
    return indexRow;
}

int RowColumnClass::getCol() const {
    return indexCol;
}

void RowColumnClass::addRowColTo(
    const RowColumnClass &inRowCol
) {
    indexRow = indexRow + inRowCol.indexRow;
    indexCol = indexCol + inRowCol.indexCol;
}

void RowColumnClass::printRowCol() const {
    cout << "[" << indexRow << "," << indexCol << "]";
}