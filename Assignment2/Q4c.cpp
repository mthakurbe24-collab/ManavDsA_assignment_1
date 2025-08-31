#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "HellO";
    int n = str.length();
    for(int i = 0; i<n;i++){
        if(str[i] == 'a'||str[i] == 'e'||str[i] == 'i'||str[i] == 'o'||str[i] == 'u'||str[i] == 'I'||str[i] == 'A'||str[i] == 'E'||str[i] == 'O'||str[i] == 'U'){
        for(int j = i; j<n - 1;j++){
            str[j] = str[j + 1];
        }
        i--;
        n--;
        }
    }
    for (int k = 0; k < n; k++) {
    cout << str[k];
}

    return 0;
}