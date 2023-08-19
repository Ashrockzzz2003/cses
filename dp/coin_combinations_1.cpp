#include <iostream>
using namespace std;

const int MOD_VALUE = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int dp[x + 1];
    for (int i = 0; i <= x; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;
    for(int i = 0; i < x + 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coins[j]) {
                dp[i] += dp[i - coins[j]];
                dp[i] %= MOD_VALUE;
            }
        }
    }

    cout << dp[x] << endl;
}

// n, x = map(int, input().split())
// coins = list(map(int, input().split()))

// dp = [0] * (x + 1)

// dp[0] = 1

// for i in range(1, x + 1):
//     for j in range(len(coins)):
//         if i >= coins[j]:
//             dp[i] += dp[i - coins[j]]

// print(dp[x] % MOD_VALUE)
