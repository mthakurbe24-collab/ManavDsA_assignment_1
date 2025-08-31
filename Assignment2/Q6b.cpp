#include <iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

int main() {
    
    const int rows = 3;
    const int cols = 3;

 
    Triplet A[] = {
        {0, 0, 3},
        {0, 2, 5},
        {1, 1, 7}
    };
    int nA = 3;

    
    Triplet B[] = {
        {0, 0, 6},
        {0, 1, 8},
        {1, 1, 2},
        {2, 2, 9}
    };
    int nB = 4;

   
    Triplet result[nA + nB];
    int nR = 0;

    int i = 0, j = 0;

 
    while (i < nA && j < nB) {
        
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result[nR++] = A[i++];
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            result[nR++] = B[j++];
        } else {
            
            int summedVal = A[i].val + B[j].val;
            if (summedVal != 0) {  
                result[nR].row = A[i].row;
                result[nR].col = A[i].col;
                result[nR].val = summedVal;
                nR++;
            }
            i++; j++;
        }
    }

    while (i < nA) result[nR++] = A[i++];
    while (j < nB) result[nR++] = B[j++];

    cout << "Result of addition (row, col, val):\n";
    for (int k = 0; k < nR; k++) {
        cout << result[k].row << " " << result[k].col << " " << result[k].val << endl;
    }

    return 0;
}
