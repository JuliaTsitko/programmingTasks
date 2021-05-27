#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

void countZ1(double alfa)
{
    double z1 = (1 - 2 * pow(sin(alfa), 2)) / (1 + sin(2 * alfa));
    cout << "The value of z1 = " << z1 << endl;
}

void countZ2(double alfa)
{
    double z2 = (1 - tan(alfa)) / (1 + tan(alfa));
    cout << "The value of z2 = " << z2 << endl;
}

bool isNumber(string x)
{
    regex e ("^-?\\d+");
    if (regex_match (x,e)) {
        return true;
    } else {
        return false;
    }
}

void countLinearAlogoritm()
{
    int alfa;
    string input;
    cout << "Enter Alfa between or equal to 0 and 360" << endl;
    cin >> input;
    alfa = isNumber(input) ? stoi(input) : -1;
    if (alfa >= 0 && alfa <= 360)
    {
        countZ1(alfa);
        countZ2(alfa);
        bool answer;
        cout << "Do you want to continue? (1 for Yes, any key for No)" << endl;
        cin >> answer;
        if (answer) {
            countLinearAlogoritm();
        } else {
            cout << "Exit" << endl;
        }
    } else {
        countLinearAlogoritm();
    }
}

int main() 
{
    countLinearAlogoritm();

    return 0;
}
