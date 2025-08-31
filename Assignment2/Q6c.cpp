#include <iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

int main() {
    const int rowsA = 2, colsA = 3;
    const int rowsB = 3, colsB = 2;

    Triplet A[] = {
        {0, 0, 1},
        {0, 2, 2},
        {1, 1, 3}
    };
    int nA = 3;

    Triplet B[] = {
        {0, 1, 4},
        {1, 0, 5},
        {2, 1, 6}
    };
    int nB = 3;

    Triplet result[rowsA * colsB * 2];
    int nR = 0;

    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            if (A[i].col == B[j].row) {
                int r = A[i].row;
                int c = B[j].col;
                int val = A[i].val * B[j].val;

                bool found = false;
                for (int k = 0; k < nR; k++) {
                    if (result[k].row == r && result[k].col == c) {
                        result[k].val += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result[nR].row = r;
                    result[nR].col = c;
                    result[nR].val = val;
                    nR++;
                }
            }
        }
    }

    cout << "Result of multiplication (row, col, val):\n";
    for (int i = 0; i < nR; i++) {
        cout << result[i].row << " " << result[i].col << " " << result[i].val << endl;
    }

    return 0;
}

