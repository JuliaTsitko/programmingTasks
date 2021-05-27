#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

string z1Text = "The value of z1 = ";
string z2Text = "The value of z2 = ";
string enterText = "Enter Alfa between or equal to 0 and 360";
string exitText = "Do you want to continue? (1 for Yes, any key for No)";

void countZ1(double alfa)
{
    double z1 = (1 - 2 * pow(sin(alfa), 2)) / (1 + sin(2 * alfa));
    cout << z1Text << z1 << endl;
}

void countZ2(double alfa)
{
    double z2 = (1 - tan(alfa)) / (1 + tan(alfa));
    cout << z2Text << z2 << endl;
}

bool isNumber(string x)
{
    regex e ("^-?\\d+");
    if (regex_match (x,e)) {
        return true;
    }
    return false;
}

int countLinearAlogoritm()
{
    int alfa;
    string input;
    cout << enterText << endl;
    cin >> input;
    alfa = isNumber(input) ? stoi(input) : -1;
    if (alfa >= 0 && alfa <= 360)
    {
        countZ1(alfa);
        countZ2(alfa);
        bool answer;
        cout << exitText << endl;
        cin >> answer;
        if (answer) {
            countLinearAlogoritm();
        }
        return 0;
    }
    countLinearAlogoritm();
}

int main() 
{
    countLinearAlogoritm();

    return 0;
}
