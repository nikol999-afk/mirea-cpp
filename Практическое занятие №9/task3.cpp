
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string toBinary(string s) {
    string binary = "";

    while (s != "0") {
        string result = "";
        int remainder = 0;

        for (int i = 0; i < s.length(); i++) {
            int number = remainder * 10 + (s[i] - '0');

            result += char(number / 2 + '0');
            remainder = number % 2;
        }

        binary += char(remainder + '0');

        int pos = result.find_first_not_of('0');

        if (pos == string::npos) {
            s = "0";
        }
        else {
            s = result.substr(pos);
        }
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string s;
    getline(fin, s);

    for (int i = 0; i < s.length();) {
        if (s[i] >= '0' && s[i] <= '9') {
            string number = "";

            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                number += s[i];
                i++;
            }

            fout << toBinary(number);
        }
        else {
            fout << s[i];
            i++;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
