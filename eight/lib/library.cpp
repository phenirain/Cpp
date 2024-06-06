#include "library.h"
#include <iostream>
#include <string>

using namespace std;

extern "C" __declspec(dllexport) bool contain(wstring line, wstring toFind) {
    if (line.find(toFind) == wstring::npos){
        return false;
    } else {
        return true;
    }
}
