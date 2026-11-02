#include <iostream>
using namespace std;

int main() {
    const int rows = 3, cols = 4;
    int a[rows][cols] = {{-5, 7, 2, 0}, {11, -3, 11, 4}, {6, 8, -1, 3}};
    int mx = a[0][0], maxRow = 0, maxCol = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (a[i][j] > mx) { mx = a[i][j]; maxRow = i; maxCol = j; }
        }
    }
    cout << "Max: " << mx << ", row index: " << maxRow
         << ", column index: " << maxCol << '\n';
    cout << "Row number: " << maxRow + 1 << ", column number: " << maxCol + 1 << '\n';
}