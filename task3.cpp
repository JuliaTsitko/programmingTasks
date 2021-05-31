#include <iostream>
#include <math.h>
#include <iomanip>
#include <string.h>
using namespace std;

// объявление констант для рассчетов примера
const double a = 0.1;
const double b = 1.0;
const double h = 0.1;
const int n = 20;

// функция подсчета факториала числа
int countFactorial(double k) {
    __int64_t factorial = 1;
    for (int i = 1; i <= k; i++) {
        factorial = factorial * i;
    }
    return factorial;
}

// функция подсчета S(x)
double countS(double x)
{
    double S;
    for (int k = 0; k < n; k++) {
        __int64_t factorial = countFactorial(k);
        S = S + ((pow(k, 2) + 1) / factorial) * pow(x / 2, k);
    }
    return S;
}

// функция подсчета Y(x)
double countY(double x)
{
    double Y;
    Y = (pow(x, 2) / 4 + x / 2 + 1) * pow(M_E, x / 2);
    return Y;
}

// функция подсчета M = |y - s|
double countM(double y, double s)
{
    double M;
    M = abs(y - s);
    return M;
}

// функция выведения хедера таблицы
void displayResultsHeader()
{
    cout << "x" << setw(18) << "S" << setw(18) << "Y"<< setw(18)  << "M" << endl;
}

// функция выведения результата подсчета в таблице
void displayResultsTable(double x, string S, string Y, string M)
{
    cout << x << setw(18) << S << setw(18) << Y << setw(18) << M << endl;
}

// функция подсчета задания
void countResults() {
    // вызов функции выведения хедера в консоль
    displayResultsHeader();
    // цикл итерация х с шагом h до b
    for (double x = a; x < b; x = x + h) {
        // сохранение резульатов подсчетов необходимых значений в переменные
        double S = countS(x);
        double Y = countY(x);
        double M = countM(Y, S);
        // приведение к строчному виду
        string sString = to_string(S);
        string yString = to_string(Y);
        string mString = to_string(M);
        // вызов функции вывода значений в консоль
        displayResultsTable(x, sString, yString, mString);
    }
}

// основная функция программы
int main() 
{
    countResults();

    return 0;
}
