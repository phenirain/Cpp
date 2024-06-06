#include <iostream>
#include <locale>
#include <fcntl.h>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    wcout << L"Введите строку:";
    wstring line;
    wcin >> line;

    wcout << L"Введите что ищете:";
    wstring toFind;
    wcin >> toFind;

    HINSTANCE load = LoadLibraryW(L"libmain.dll");

    typedef bool (*contain)(std::wstring, std::wstring);
    contain Contain = (contain)GetProcAddress(load, "contain");

    if (Contain(line, toFind)){
        wcout << L"Да!";
    } else {
        wcout << L"Нету!";
    }

    FreeLibrary(load);

    return 0;
}