
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int left = 0;
    int right = a[n - 1] - a[0];

    while (left < right) {
        int mid = (left + right) / 2;

        int days = 0;
        int i = 0;

        while (i < n) {
            int j = i;

            while (j < n && a[j] - a[i] <= mid) {
                j++;
            }

            days++;
            i = j;
        }

        if (days <= d) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}
