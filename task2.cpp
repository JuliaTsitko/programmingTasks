#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

string enterText = "Enter Z number: ";
string exitText = "Do you want to continue? (1 for Yes, any key for No)";
string resultText = "Function result = ";
string positiveText = "x > 0 The Result: ";
string negativeText = "x <= 0 The Result: ";

bool isNumber(string x)
{
    regex e ("^-?\\d+");
    if (regex_match (x,e)) {
        return true;
    }
    return false;
}

double countX(double z)
{
    double x;
    if (z > 0) {
        x = 1 / (pow(z, 2) + 2 * z);
        cout << positiveText << x << endl;
        return x;
        
    }
    x = 1 - pow(z, 3);
    cout << negativeText << x << endl;
    return x;
}

double countY(double x) 
{
    double y = (2 * pow(M_E, -3 * x) - 4 * pow(x, 2)) / (log(abs(x)) + x);
    return y;
}

int countFunction()
{
    int z;
    string input;
    cout << enterText << endl;
    cin >> input;
    if (isNumber(input)) {
        z = stoi(input);
        double x = countX(z);
        double y = countY(x);
        cout << resultText << y << endl;

        bool isContinue;
        cout << exitText << endl;
        cin >> isContinue;
        if (isContinue) {
            countFunction();
        }
        return 0;
    }
    countFunction();
}

int main() 
{
    countFunction();
    return 0;
}