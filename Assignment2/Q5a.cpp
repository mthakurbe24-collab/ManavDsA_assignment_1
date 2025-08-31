#include <iostream>
using namespace std;

class DiagonalMatrix {
    int arr[100]; 
    int n;

public:
    DiagonalMatrix(int size) {
        if (size > 100) {
            cout << "Size too large, max allowed is 100." << endl;
            n = 100;
        } else {
            n = size;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }

    void set(int i, int j, int value) {
        if (i == j && i >= 1 && i <= n) {
            arr[i - 1] = value;
        }
    }

    int get(int i, int j) {
        if (i == j && i >= 1 && i <= n) {
            return arr[i - 1];
        }
        return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    cout << arr[i - 1] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter size of diagonal matrix (max 100): ";
    cin >> size;

    DiagonalMatrix dm(size);

    cout << "Enter diagonal elements: "<<endl;;
    for (int i = 1; i <= size; i++) {
        int val;
        cin >> val;
        dm.set(i, i, val);
    }

    cout << "The matrix is: "<<endl;
    dm.display();

    return 0;
}
