#include <iostream>
using namespace std;


class BankAccount {
    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
private:
    int _accountNumber;
    double _balance;
    double _interestRate;
public:
    void deposit(int amount) {
        if (amount > 0) {
            _balance += amount;
        }
        else {
            cout << "Нельзя пополнить баланс на отрицательное число или нуль(\n";
        }
    }
    void withdraw(int amount) {
        if (amount <= _balance) {
            _balance -= amount;
        }
    }
    int getBalance() {
        return _balance;
    }
    double getInterest() {
        return _balance * _interestRate * (1.0 / 12) ? _interestRate > 0: 0;
    }
    void setInterest(double interest) {
        if (interest > 0) {
            _interestRate = interest;
        }
        else {
            cout << "Процентная ставка не может быть меньше нуля или равна ему(\n";
        }
    }
    int getAccountNumber() {
        return _accountNumber;
    }

    BankAccount(int accountNumber, double balance) {
        this->_accountNumber = accountNumber;
        this->_balance = balance;
    }
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from._balance >= amount) {
        from._balance -= amount;
        to._balance += amount;
        return true;
    }
    else return false;
}

int main()
{
    setlocale(LC_ALL, "");
    BankAccount account_1(111, 100);
    BankAccount account_2(222, 200);
    account_1.deposit(113);
    account_2.deposit(113);
    cout << "Баланс 1 пользователя: " << account_1.getBalance() << endl;
    cout << "Баланс 2 пользователя: " << account_2.getBalance() << endl;
    account_1.setInterest(-1);
    account_2.setInterest(0.15);
    cout << "Проценты 1 пользователя: " << account_1.getInterest() << endl;
    cout << "Проценты 2 пользователя: " << account_2.getInterest() << endl;
    account_1.withdraw(11);
    account_2.withdraw(22);
    cout << "Баланс 1 пользователя: " << account_1.getBalance() << endl;
    cout << "Баланс 2 пользователя: " << account_2.getBalance() << endl;
    cout << "Статус перевода с 1 на 2: " << transfer(account_1, account_2, 200) << endl;
    cout << "Статус перевода с 1 на 2: " << transfer(account_1, account_2, 200) << endl;
}