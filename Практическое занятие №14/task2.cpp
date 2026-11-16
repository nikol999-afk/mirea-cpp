
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    set<string> words;
    string word;

    for (char c : s) {
        if (isalpha((unsigned char)c) || c == '-') {
            word += tolower((unsigned char)c);
        }
        else {
            if (!word.empty()) {
                words.insert(word);
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        words.insert(word);
    }

    for (string w : words) {
        cout << w << endl;
    }

    return 0;
}
