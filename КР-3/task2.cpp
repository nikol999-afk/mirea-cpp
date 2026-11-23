
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Ошибка открытия файла";
        return 1;
    }

    int year;
    cout << "Введите год: ";
    cin >> year;

    string name;
    int filmYear;

    while (getline(fin, name)) {
        if (name.empty()) {
            continue;
        }

        if (!(fin >> filmYear)) {
            break;
        }

        fin.ignore();

        if (filmYear > year) {
            fout << name << endl;
        }
    }

    fin.close();
    fout.close();

    cout << "Результат записан в output.txt";

    return 0;
}
