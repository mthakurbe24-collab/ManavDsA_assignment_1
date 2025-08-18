#include <iostream>
using namespace std;

int main() {
int arr[] = {64,35,25,12,22,11,90};
int size_arr = sizeof(arr)/sizeof(arr[0]) ;
for(int i = 0 ; i<size_arr - 1; i++){
for(int j = 0;j<size_arr - 1 - i;j++){
if (arr[j] > arr[j + 1]) {
int temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}

}

}

for(int i = 0; i<size_arr; i++){
cout<<arr[i]<<endl;
}

return 0;

}