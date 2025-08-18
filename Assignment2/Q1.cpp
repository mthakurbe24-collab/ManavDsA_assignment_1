#include <iostream>
using namespace std;

int main() {
int arr[] = {1,2,3,4,5,6};
int si_ze = sizeof(arr)/sizeof(arr[0]);
int n;
bool found = true;

cout<<"Enter the number you want to find : "<<endl;
cin>>n;
int min = 0 ;
int max = si_ze - 1;

while(min<=max){

int mid = (min + max)/2;

if(arr[mid] == n){
cout<<"Number found at index: "<<mid<<endl;
found = true;
break;
}
else if(arr[mid]<n){
min = mid + 1;
}
else{
max = mid - 1;
}

}

if(!found){
cout<<"Number do not exist in the array";
}

return 0;
}