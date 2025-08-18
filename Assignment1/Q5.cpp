#include <iostream> 
using namespace std; 
  
int main() { 
    int rows, cols; 
    int matrix[100][100]; 
  
    cout << "Enter number of rows and columns: "; 
    cin >> rows >> cols; 
  
    cout << "Enter elements of the matrix:" << endl; 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            cin >> matrix[i][j]; 
        } 
    } 
  
    cout << "\nMatrix:" << endl; 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            cout << matrix[i][j] << " "; 
        } 
        cout << endl; 
    } 
    
    cout << "\nSum of each row:" << endl; 
    for (int i = 0; i < rows; i++) { 
        int rowSum = 0; 
        for (int j = 0; j < cols; j++) { 
            rowSum += matrix[i][j]; 
        } 
        cout << "Row " << i + 1 << ": " << rowSum << endl; 
    } 
  
    cout << "\nSum of each column:" << endl; 
    for (int j = 0; j < cols; j++) { 
        int colSum = 0; 
        for (int i = 0; i < rows; i++) { 
            colSum += matrix[i][j]; 
        } 
        cout << "Column " << j + 1 << ": " << colSum << endl; 
    } 
  
    return 0; 
}