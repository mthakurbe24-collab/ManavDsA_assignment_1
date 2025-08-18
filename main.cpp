#include <iostream> 
using namespace std; 
  
int main() { 
    int arr[1000]; 
    int n; 
  
    cout << "Enter the number of array elements: "; 
    cin >> n; 
  
    cout << "Enter the elements of the array: "; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
  
    int choice; 
    do { 
        cout << "\n===== MENU =====" << endl; 
        cout << "1. Display Array" << endl; 
        cout << "2. Insert Element" << endl; 
        cout << "3. Delete Element" << endl; 
        cout << "4. Search Element" << endl; 
        cout << "5. Exit" << endl; 
        cout << "Enter your choice: "; 
        cin >> choice; 
  
        switch (choice) { 
            case 1: 
                cout << "Array elements: "; 
                for (int i = 0; i < n; i++) { 
                    cout << arr[i] << " "; 
                } 
                cout << endl; 
                break; 
  
            case 2: { 
                int x, pos; 
                cout << "Enter the element and position to insert: "; 
                cin >> x >> pos; 
                if (pos < 0 || pos > n) { 
                    cout << "Invalid position.\n"; 
                } else { 
                    for (int i = n; i > pos; i--) { 
                        arr[i] = arr[i - 1]; 
                    } 
                    arr[pos] = x; 
                    n++; 
                    cout << "Element inserted.\n"; 
                } 
                                cout << "Array elements: "; 
                for (int i = 0; i < n; i++) { 
                    cout << arr[i] << " "; 
                } 
                cout << endl; 
                break; 
            } 
  
            case 3: { 
                int pos; 
                cout << "Enter the position to delete: "; 
                cin >> pos; 
                if (pos < 0 || pos >= n) { 
                    cout << "Invalid position.\n"; 
                } else { 
                    for (int i = pos; i < n - 1; i++) { 
                        arr[i] = arr[i + 1]; 
                    } 
                    n--; 
                    cout << "Element deleted.\n"; 
                } 
                                cout << "Array elements: "; 
                for (int i = 0; i < n; i++) { 
                    cout << arr[i] << " "; 
                } 
                cout << endl; 
                break; 
            } 
  
            case 4: { 
                int key; 
                cout << "Enter the element to search: "; 
                cin >> key; 
                bool found = false; 
                for (int i = 0; i < n; i++) { 
                    if (arr[i] == key) { 
                        cout << "Element found at index " << i << endl; 
                        found = true; 
                        break; 
                    } 
                } 
                if (!found) { 
                    cout << "Element not found.\n"; 
                } 
                break; 
            } 
  
            case 5: 
                cout << "Exiting program. Goodbye!" << endl; 
                break; 
  
            default: 
                cout << "Invalid choice. Try again.\n"; 
        } 
  
    } while (choice != 5); 
    return 0;
}