#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int a[n] = {8, -3, 12, 8, -3, 5, 12, 0, 12, -3};
    int mn = a[0], mx = a[0];
    int minIndex = 0, maxIndex = 0;
    int minCount = 1, maxCount = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] < mn) { mn = a[i]; minIndex = i; minCount = 1; }
        else if (a[i] == mn) { ++minCount; }
        if (a[i] > mx) { mx = a[i]; maxIndex = i; maxCount = 1; }
        else if (a[i] == mx) { ++maxCount; }
    }
    cout << "Min: " << mn << ", index: " << minIndex
         << ", number: " << minIndex + 1 << ", count: " << minCount << '\n';
    cout << "Max: " << mx << ", index: " << maxIndex
         << ", number: " << maxIndex + 1 << ", count: " << maxCount << '\n';
}