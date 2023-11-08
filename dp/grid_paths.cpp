#include <iostream>
#include <vector>
using namespace std;

int count_grid_paths(vector<vector<char>> &G, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // To go from (0, 0) to (0, 0) there is only one way
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] != '*') {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j] % 1000000007;
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1] % 1000000007;
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    return dp[n - 1][n - 1] % 1000000007;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> G(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    cout << count_grid_paths(G, n) << endl;
    return 0;
}