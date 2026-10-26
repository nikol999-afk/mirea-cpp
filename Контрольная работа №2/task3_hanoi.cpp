
#include <iostream>
using namespace std;

void move(int n, int from, int to, int temp) {
    if (n == 1) {
        cout << "Ingredient 1 move from " << from << " to " << to << endl;
        return;
    }

    move(n - 1, from, temp, to);

    cout << "Ingredient " << n << " move from " << from << " to " << to << endl;

    move(n - 1, temp, to, from);
}

int main() {
    int n;
    cin >> n;

    move(n, 1, 3, 2);

    return 0;
}
