#include <iostream>
#include <cmath>

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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << e.what() << endl;
                i--;
            }
        }
        cout << endl;
        return numbers;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    bool work = true;
    do {
        cout << "Выберите операцию:" << endl;
        cout << "1. Сложить 2 числа" << endl;
        cout << "2. Вычесть второе из первого" << endl;
        cout << "3. Перемножить два числа" << endl;
        cout << "4. Разделить первое на второе" << endl;
        cout << "5. Возвести в степень N первое число" << endl;
        cout << "6. Найти квадратный корень из числа" << endl;
        cout << "7. Найти 1 процент от числа" << endl;
        cout << "8. Найти факториал из числа" << endl;
        cout << "9. Выйти из программы" << endl << endl;
        cout << "Ваша команда: ";
        string operation;
        cin >> operation;
        cout << endl;
        double* numbers;
        switch (atoi(operation.c_str())) {
        case 1: {
            // Вызываем функцию для ввода двух чисел
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
                cout << "На ноль делить нельзя(" << endl;
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
            cout << "Корень из " << numbers[0] << " = " << res << endl;
            cout << endl;
            delete[] numbers;
            break;
        }
        case 7: {
            numbers = Calculator::getNums(1);
            double res = numbers[0] * 0.01;
            cout << "1% от " << numbers[0] << " = " << res << endl;
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
                cout << "Нельзя вычислить факториал из отрицательного числа(" << endl;
                cout << endl;
            }
            delete[] numbers;
            break;
        }
        case 9: {
            work = false;
            cout << "Вычисления завершены!" << endl;
            break;
        }
        default: {
            cout << "Я не знаю такую команду(" << endl;
            cout << endl;
            break;
        }
        }
    } while (work);
    return 0;
}




