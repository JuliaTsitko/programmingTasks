#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

// объявление строковых переменных с сохранением значений выводимого в консоль текста
string enterText = "Enter Z number: ";
string exitText = "Do you want to continue? (1 for Yes, any key for No)";
string resultText = "Function result = ";
string positiveText = "x > 0 The Result: ";
string negativeText = "x <= 0 The Result: ";

// функция принимающая строковое значение, проверяющее может ли оно являться числовым значением, возвращает булиновое значение
bool isNumber(string x)
{
    // регексп на определение являются ли все символы полученной строки цифрами
    regex e ("^-?\\d+");
    if (regex_match (x,e)) {
        return true;
    }
    return false;
}

// функция вычисления и возвращения значения х, принимающая аргумент z
double countX(double z)
{
    double x;
    // вычисление при z > 0
    if (z > 0) {
        x = 1 / (pow(z, 2) + 2 * z);
        // вывод сообщения из ветви z > 0
        cout << positiveText << x << endl;
        return x;
        
    }
    // вычисление при z <= 0
    x = 1 - pow(z, 3);
    // вывод сообщения из ветви z <= 0
    cout << negativeText << x << endl;
    return x;
}

// функция вычисления и врзвращения значения y, принимающая аргумент x
double countY(double x) 
{
    double y = (2 * pow(M_E, -3 * x) - 4 * pow(x, 2)) / (log(abs(x)) + x);
    return y;
}

// функция подсчета
int countFunction()
{
    // объявление переменной для числового значения
    int z;
    // объявление переменной для введения строкового значения
    string input;
    // выведение начального текста с информацией о вводимых параметрах
    cout << enterText << endl;
    // сохранение вводимого значения в переменную
    cin >> input;
    // проверка значения, является ли он числом
    if (isNumber(input)) {
        // преобразование и сохранение числового значения
        z = stoi(input);
        // сохранения результатов вычислений
        double x = countX(z);
        double y = countY(x);
        // вывод результатов вычислений в консоль
        cout << resultText << y << endl;

        // объявление переменной
        bool isContinue;
        // вывод текста возможного завершения программы
        cout << exitText << endl;
        // сохранение вводимого значения из консоли в переменную
        cin >> isContinue;
        // проверка введенного значения
        if (isContinue) {
            // повторный вызов программы
            countFunction();
        }
        // завершение программы
        return 0;
    }
    // повторный вызов программы при введении невалидного значения
    countFunction();
}

// основная функция выполнения программы
int main() 
{
    countFunction();
    return 0;
}