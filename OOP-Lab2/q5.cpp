#include <iostream>
#include <cstring>
using namespace std;
char* swap_string(char* str, int n) {
    int length = strlen(str);
    if (n <= 0 || n >= length){
        return str;
    }
    char* new_str = new char[length];
    for (int i = 0; i < n; ++i) {
        new_str[i] = str[length - n + i];
        new_str[length - n + i] = str[i];
    }
    for (int i = n; i < length - n; ++i) {
        new_str[i] = str[i];
    }
    return new_str;
}
int main() {
    char str[20] ;
    int n ;
    cout << "Enter a string to convert: " ;
    cin >> str ;
    cout << "Enter value of n: " ;
    cin >> n ;
    char* result = swap_string(str, n);
    cout << result << endl;
    return 0;
}