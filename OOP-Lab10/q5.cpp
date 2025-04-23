#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream dataFile("data.txt");
    dataFile << "AI is the future. AI will transform the world. Embrace AI now.";
    dataFile.close();

    string searchWord, replacementWord;
    cin >> searchWord >> replacementWord;
    fstream data("data.txt", ios::in | ios::out);
    string fileData;
    char ch;
    while (data.get(ch)) {
        fileData += ch;
    }
    data.clear();
    data.seekg(0);
    size_t pos = fileData.find(searchWord);
    while (pos != string::npos) {
        data.seekp(pos);
        data << replacementWord;
        if (replacementWord.length() < searchWord.length()) {
            for (int i = 0; i < searchWord.length() - replacementWord.length(); i++) {
                data << ' ';
            }
        }
        pos = fileData.find(searchWord, pos + searchWord.length());
    }
    data.close();

    ifstream updated("data.txt");
    string line;
    while (getline(updated, line)) {
        cout << line << endl;
    }
    updated.close();
    return 0;
}