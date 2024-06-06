#ifndef CONTAIN_LIBRARY_H
#define CONTAIN_LIBRARY_H

#include <string>

using namespace std;
extern "C" __declspec(dllexport) bool contain(wstring line, wstring toFind);

#endif //CONTAIN_LIBRARY_H
