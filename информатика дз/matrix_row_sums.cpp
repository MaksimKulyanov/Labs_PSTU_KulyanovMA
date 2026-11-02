#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int rows = 3, cols = 4;
    int a[rows][cols] = {{-5, 7, 2, 0}, {11, -3, 11, 4}, {6, 8, -1, 3}};
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << a[i][j];
            sum += a[i][j];
        }
        cout << "   Sum: " << sum << '\n';
    }
}