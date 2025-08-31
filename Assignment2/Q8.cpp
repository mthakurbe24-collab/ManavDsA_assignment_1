#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool Distinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                Distinct = false;
                break;
            }
        }
        if (Distinct) count++;
    }

    cout << "Total distinct elements: " << count << endl;
    return 0;
}



