#include <iostream>
#include <cmath>
#include <Windows.h>
// -*- coding: utf-8 -*-

using namespace std;

class Calculator {
public:
    static int factorial(int n) {
        return (n == 0) ? 1 : n * factorial(n - 1);
    }
    static double* getNums(int numCount) {
        double* numbers = new double[numCount];
        for (int i = 0; i < numCount; i++) {
            cout << "Введите " << i + 1 << " число: ";

            try {
                cin >> numbers[i];
                if (cin.fail()) {
                    throw invalid_argument("Вы должны ввести именно число!");
                }
            }
            catch (const invalid_argument& e) {
                cin.clear(); 
                cout << e.what() << endl;
                i--;
            }
        }
        cout << endl;
        return numbers;
    }
};

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");
    bool work = true;
    do {
        cout << "Âûáåðèòå îïåðàöèþ:" << endl;
        cout << "1. Ñëîæèòü 2 ÷èñëà" << endl;
        cout << "2. Âû÷åñòü âòîðîå èç ïåðâîãî" << endl;
        cout << "3. Ïåðåìíîæèòü äâà ÷èñëà" << endl;
        cout << "4. Ðàçäåëèòü ïåðâîå íà âòîðîå" << endl;
        cout << "5. Âîçâåñòè â ñòåïåíü N ïåðâîå ÷èñëî" << endl;
        cout << "6. Íàéòè êâàäðàòíûé êîðåíü èç ÷èñëà" << endl;
        cout << "7. Íàéòè 1 ïðîöåíò îò ÷èñëà" << endl;
        cout << "8. Íàéòè ôàêòîðèàë èç ÷èñëà" << endl;
        cout << "9. Âûéòè èç ïðîãðàììû" << endl << endl;
        cout << "Âàøà êîìàíäà: ";
        string operation;
        cin >> operation;
        cout << endl;
        double* numbers;
        switch (atoi(operation.c_str())) {
        case 1: {
            numbers = Calculator::getNums(2);
            cout << numbers[0] << " + " << numbers[1] << " = " << numbers[0] + numbers[1] << endl;
            cout << endl;
            delete[] numbers;
            break;
        }
        case 2: {
            numbers = Calculator::getNums(2);
            cout << numbers[0] << " - " << numbers[1] << " = " << numbers[0] - numbers[1] << endl;
            cout << endl;
            delete[] numbers;
            break;
        }
        case 3: {
            numbers = Calculator::getNums(2);
            cout << numbers[0] << " * " << numbers[1] << " = " << numbers[0] * numbers[1] << endl;
            cout << endl;
            delete[] numbers;
            break;
        }
        case 4: {
            numbers = Calculator::getNums(2);
            if (numbers[1] == 0) {
                cout << "Íà íîëü äåëèòü íåëüçÿ(" << endl;
                cout << endl;
            }
            else {
                cout << numbers[0] << " / " << numbers[1] << " = " << numbers[0] / numbers[1] << endl;
                cout << endl;
            }
            delete[] numbers;
            break;
        }
        case 5: {
            numbers = Calculator::getNums(2);
            double res = pow(numbers[0], numbers[1]);
            cout << numbers[0] << "^" << numbers[1] << " = " << res << endl;
            cout << endl;
            delete[] numbers;
            break;
        }
        case 6: {
            numbers = Calculator::getNums(1);
            double res = sqrt(numbers[0]);
            cout << "Êîðåíü èç " << numbers[0] << " = " << res << endl;
            cout << endl;
            delete[] numbers;
            break;
        }
        case 7: {
            numbers = Calculator::getNums(1);
            double res = numbers[0] * 0.01;
            cout << "1% îò " << numbers[0] << " = " << res << endl;
            cout << endl;
            delete[] numbers;
            break;
        }
        case 8: {
            numbers = Calculator::getNums(1);
            if (numbers[0] >= 0) {
                double res = Calculator::factorial(static_cast<int>(round(numbers[0])));
                cout << numbers[0] << "! = " << res << endl;
                cout << endl;
            }
            else {
                cout << "Íåëüçÿ âû÷èñëèòü ôàêòîðèàë èç îòðèöàòåëüíîãî ÷èñëà(" << endl;
                cout << endl;
            }
            delete[] numbers;
            break;
        }
        case 9: {
            work = false;
            cout << "Âû÷èñëåíèÿ çàâåðøåíû!" << endl;
            break;
        }
        default: {
            cout << "ß íå çíàþ òàêóþ êîìàíäó(" << endl;
            cout << endl;
            break;
        }
        }
    } while (work);
    return 0;
}




