#include <iostream>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // x -> target sum
    int dp[x + 1];

    for(int i = 0; i <= x; i++) {
        dp[i] = -1;
    }

    dp[0] = 0;
    for(int i = 1; i < x + 1; i++) {
        for(int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                if (dp[i] == -1) {
                    dp[i] = dp[i - coins[j]] + 1;
                } else {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
    }

    cout << dp[x] << endl;

}

int main() {
    solve();
}