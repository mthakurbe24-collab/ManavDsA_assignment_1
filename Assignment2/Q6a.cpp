#include <iostream>
using namespace std;

struct Triplet {
    int row;
    int col;
    int val;
};

int main() {
    const int rows = 3;
    const int cols = 4;
    const int nonZero = 4;

    Triplet matrix[nonZero] = {
        {0, 1, 5},
        {0, 3, 10},
        {1, 2, 8},
        {2, 0, 15}
    };

    Triplet transpose[nonZero];

    for (int i = 0; i < nonZero; i++) {
        transpose[i].row = matrix[i].col;
        transpose[i].col = matrix[i].row;
        transpose[i].val = matrix[i].val;
    }

    cout << "Transposed matrix triplets (row, col, val):" << endl;
    for (int i = 0; i < nonZero; i++) {
        cout << transpose[i].row << " " << transpose[i].col << " " << transpose[i].val << endl;
    }

    return 0;
}
