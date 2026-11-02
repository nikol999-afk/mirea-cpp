#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin1("input1_task2.txt");
    ifstream fin2("input2_task2.txt");
    ofstream fout("output.txt");

    string X, Y;

    getline(fin1, X);
    getline(fin2, Y);

    if (X.find(Y) != string::npos) {
        fout << "yes";
    }
    else {
        fout << "no";
    }

    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}