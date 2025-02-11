#include <iostream>
#include <cstring>
using namespace std;
int countVowels(const char* str) {
    int vowels = 0;
    for (int i = 0; *(str + i) != '\0'; ++i) {
        char ch = *(str + i);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowels++;
        }
    }
    return vowels;
}
int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    char** arr = new char*[n];
    cout << "Enter " << n << " strings:" << endl;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        arr[i] = new char[100];
        cin.getline(arr[i], 100);
    }
    cout << "Strings in reverse order:" << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << *(arr + i) << endl;
    }
    int maxVowels = countVowels(*(arr));
    char* mostVowelsString = *(arr);
    for (int i = 1; i < n; ++i) {
        int vowels = countVowels(*(arr + i));
        if (vowels > maxVowels) {
            maxVowels = vowels;
            mostVowelsString = *(arr + i);
        }
    }
    cout << "String with the most vowels: " << mostVowelsString << endl;
    float totalLength = 0;
    for (int i = 0; i < n; ++i) {
        totalLength += strlen(*(arr + i));
    }
    float averageLength = totalLength / n;
    cout << "Average length of all strings: " << averageLength << endl;
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
