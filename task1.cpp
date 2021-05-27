#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

// объявление строковых переменных с сохранением значений выводимого в консоль текста
string z1Text = "The value of z1 = ";
string z2Text = "The value of z2 = ";
string enterText = "Enter Alfa between or equal to 0 and 360";
string exitText = "Do you want to continue? (1 for Yes, any key for No)";

// функция подсчитывающая и возвращающая значение z1, принимает вводимый из консоли параметр alfa
double countZ1(double alfa)
{
    double z1 = (1 - 2 * pow(sin(alfa), 2)) / (1 + sin(2 * alfa));
    return z1;
}

// функция подсчитывающая и возвращающая значение z2, принимает вводимый из консоли параметр alfa
double countZ2(double alfa)
{
    double z2 = (1 - tan(alfa)) / (1 + tan(alfa));
    return z2;
}

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

// функция калькуляции и вывода
int countLinearAlogoritm()
{
    // объявление переменной для сохранение числового значения
    int alfa;
    // объявление переменной для введения строкового значения
    string input;
    // выведение начального текста с информацией о вводимых параметрах
    cout << enterText << endl;
    // сохранение вводимого значения в переменную
    cin >> input;
    // проверка введенного значения, приведение к числовому типу и сохранение значения (или сохранение отрицательного значения, если были введены символы или буквы)
    alfa = isNumber(input) ? stoi(input) : -1;
    // проверка диапазона вводимых значений
    if (alfa >= 0 && alfa <= 360)
    {
        // сохранения результатом вычислений
        double z1 = countZ1(alfa);
        double z2 = countZ2(alfa);
        // вывод результатов вычислений в консоль
        cout << z1Text << z1 << endl << z2Text << z2 << endl;

        // объявление переменной
        bool isContinue;
        // вывод текста возможного завершения программы
        cout << exitText << endl;
        // сохранение вводимого значения из консоли в переменную
        cin >> isContinue;
        // проверка введенного значения
        if (isContinue) {
            // повторный вызов программы
            countLinearAlogoritm();
        }
        // завершение программы
        return 0;
    }
    // повторный вызов программы при введении невалидного значения
    countLinearAlogoritm();
}

// основная функция выполнения программы
int main() 
{
    countLinearAlogoritm();

    return 0;
}
