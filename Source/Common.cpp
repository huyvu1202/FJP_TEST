#include "../Header/Common.h"

using namespace std;
#define RANGE_MIN 0
#define RANGE_MAX 999

void showValue(QueueTemplate const value) {
    cout << "ID\t: " << value.iD << endl;
    cout << "Pos x\t: " << value.xPos << endl;
    cout << "Pos y\t: " << value.yPos << endl;
    cout << "Name\t: " << value.name << endl;
    cout << endl;
    return;
};

bool validateInputData(QueueTemplate const value)
{
    if (value.iD > RANGE_MAX || value.iD < RANGE_MIN)
        return false;
    return true;
};
