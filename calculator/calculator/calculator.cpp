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
            cout << "������� " << i + 1 << " �����: ";

            try {
                cin >> numbers[i];
                if (cin.fail()) {
                    throw invalid_argument("�� ������ ������ ������ �����!");
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
        cout << "�������� ��������:" << endl;
        cout << "1. ������� 2 �����" << endl;
        cout << "2. ������� ������ �� �������" << endl;
        cout << "3. ����������� ��� �����" << endl;
        cout << "4. ��������� ������ �� ������" << endl;
        cout << "5. �������� � ������� N ������ �����" << endl;
        cout << "6. ����� ���������� ������ �� �����" << endl;
        cout << "7. ����� 1 ������� �� �����" << endl;
        cout << "8. ����� ��������� �� �����" << endl;
        cout << "9. ����� �� ���������" << endl << endl;
        cout << "���� �������: ";
        string operation;
        cin >> operation;
        cout << endl;
        double* numbers;
        switch (atoi(operation.c_str())) {
        case 1: {
            // �������� ������� ��� ����� ���� �����
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
                cout << "�� ���� ������ ������(" << endl;
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
            cout << "������ �� " << numbers[0] << " = " << res << endl;
            cout << endl;
            delete[] numbers;
            break;
        }
        case 7: {
            numbers = Calculator::getNums(1);
            double res = numbers[0] * 0.01;
            cout << "1% �� " << numbers[0] << " = " << res << endl;
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
                cout << "������ ��������� ��������� �� �������������� �����(" << endl;
                cout << endl;
            }
            delete[] numbers;
            break;
        }
        case 9: {
            work = false;
            cout << "���������� ���������!" << endl;
            break;
        }
        default: {
            cout << "� �� ���� ����� �������(" << endl;
            cout << endl;
            break;
        }
        }
    } while (work);
    return 0;
}




