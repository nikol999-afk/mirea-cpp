
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    dp[0][0] = a[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                continue;

            int top = (i > 0) ? dp[i - 1][j] : -1000000000;
            int left = (j > 0) ? dp[i][j - 1] : -1000000000;

            dp[i][j] = a[i][j] + max(top, left);
        }
    }

    vector<pair<int, int>> path;

    int i = n - 1;
    int j = m - 1;

    while (true) {
        path.push_back({i, j});

        if (i == 0 && j == 0)
            break;

        if (i == 0) {
            j--;
        }
        else if (j == 0) {
            i--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(path.begin(), path.end());

    for (auto p : path) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
