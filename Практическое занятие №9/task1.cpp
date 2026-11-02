
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("input_task1.txt");
    ofstream fout("output.txt");

    string s;
    string letters = "user agreement";

    getline(fin, s);

    for (int i = 0; i < s.length(); i++) {
        char c = tolower(s[i]);

        if (letters.find(c) == string::npos) {
            fout << s[i];
        }
    }

    fin.close();
    fout.close();

    return 0;
}
