

#include <iostream>

using namespace std;
int main()
{
    double arr[3][5];
    double sum = 0.0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            double n;
            cout << "Input a value:";
            cin >> n;
            arr[i][j] = n;
            sum += n;
        }
    }
    sum = sum / 15;
    cout << "Average of matrix: " << sum;
    return 0;
}
