#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str = "What";
    int n = str.length();

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(tolower(str[j]) > tolower(str[j + 1])) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    cout << str << endl;
    return 0;
}
