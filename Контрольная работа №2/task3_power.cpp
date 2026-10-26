
#include <iostream>
using namespace std;

long long power(long long a, int n) {
    long long result = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            result *= a;
        }

        a *= a;
        n /= 2;
    }

    return result;
}

int main() {
    long long a;
    int n;

    cin >> a >> n;
    cout << power(a, n);

    return 0;
}
