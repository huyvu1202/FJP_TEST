#ifndef COMMON
#define COMMON

#include <iostream>
using namespace std;

//Define Value Template
struct QueueTemplate {
    unsigned int iD;    // id of car
    int xPos;           // x position 
    int yPos;           // y positio
    char name[4];       // serialnumber
};

void showValue(QueueTemplate const value);
bool validateInputData(QueueTemplate const value);

#endif // COMMON
