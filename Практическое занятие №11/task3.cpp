
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int sum = 0;
    int count = 0;

    for (int i = 0; i < n && count < k; i++) {
        for (int j = 0; j < l && count < k; j++) {
            sum += a[i];
            count++;
        }
    }

    cout << sum << endl;

    return 0;
}
