#include <iostream> 
using namespace std; 
  
int main() { 
    int A[10][10], B[10][10], C[10][10] = {0}; 
    int m, n, p; 
  
    cout << "Enter rows and columns of Matrix A (m x n): "; 
    cin >> m >> n; 
  
    cout << "Enter rows of Matrix B (should be " << n << ") and columns (p): "; 
    int n2; 
    cin >> n2 >> p; 
  
    if (n != n2) { 
        cout << "Matrix multiplication not possible (columns of A != rows of B)." << endl; 
        return 0; 
    } 
  
    cout << "Enter elements of Matrix A:" << endl; 
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            cin >> A[i][j]; 
  
    cout << "Enter elements of Matrix B:" << endl; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < p; j++) 
            cin >> B[i][j]; 
  
    
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < p; j++) { 
            for (int k = 0; k < n; k++) { 
                C[i][j] += A[i][k] * B[k][j]; 
            } 
        } 
    } 
  
    cout << "Resultant Matrix C = A x B:" << endl; 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < p; j++) { 
            cout << C[i][j] << " "; 
        } 
        cout << endl; 
    } 
  
    return 0; 
} 