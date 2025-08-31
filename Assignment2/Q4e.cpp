#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char cha = 'W';

    if (isupper(cha)) {
        cout<<"Original: "<<cha<<endl;
        cha = tolower(cha);
        cout << "Lowercase: " << cha << endl;
    } else {
        cout << "not uppercase." << endl;
    }

    return 0;
}
