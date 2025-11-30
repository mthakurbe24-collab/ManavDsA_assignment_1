#include <iostream>
using namespace std;

class HeapSort {
private:
  
    void heapify(int arr[], int n, int i, bool increasing) {
        int extreme = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (increasing) {
           
            if (left <= n && arr[left] > arr[extreme])
                extreme = left;
            if (right <= n && arr[right] > arr[extreme])
                extreme = right;
        } else {
           
            if (left <= n && arr[left] < arr[extreme])
                extreme = left;
            if (right <= n && arr[right] < arr[extreme])
                extreme = right;
        }

        if (extreme != i) {
            swap(arr[i], arr[extreme]);
            heapify(arr, n, extreme, increasing);
        }
    }

public:
    void sort(int arr[], int n, bool increasing = true) {

        for (int i = n / 2; i >= 1; i--)
            heapify(arr, n, i, increasing);

      
        for (int i = n; i >= 2; i--) {
            swap(arr[1], arr[i]);
            heapify(arr, i - 1, 1, increasing);
        }
    }

    void printArray(int arr[], int n) {
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int arr[]  = {0, 12, 11, 13, 5, 6, 7};
    int arr2[] = {0, 12, 11, 13, 5, 6, 7};
    int n = 6;

    HeapSort hs;

    cout << "Increasing order: ";
    hs.sort(arr, n, true);
    hs.printArray(arr, n);

    cout << "Decreasing order: ";
    hs.sort(arr2, n, false);
    hs.printArray(arr2, n);

    return 0;
}