#include <iostream>
#include <vector>
using namespace std;

const int MOD_VALUE = 1e9 + 7;

// int distictOrderedWays(int index, int sum, int coins[], vector<vector<int> > &dp) {
//     if (sum == 0) {
//         return dp[index][sum] = 1;
//     }

//     if (index < 0 || sum < 0) {
//         return 0;
//     }

//     if(index == 0 && sum % coins[index] == 0) {
//         return dp[index][sum] = 1;
//     }

//     if (index == 0 && sum % coins[index] != 0) {
//         return dp[index][sum] = 0;
//     }

//     if (dp[index][sum] != -1) {
//         return dp[index][sum] % MOD_VALUE;
//     }

//     int no_of_ways = 0;

//     // take the coin
//     if (sum - coins[index] >= 0) {
//         no_of_ways += distictOrderedWays(index, sum - coins[index], coins, dp);
//     }

//     // don't take the coin
//     no_of_ways += distictOrderedWays(index - 1, sum, coins, dp);

//     return dp[index][sum] = no_of_ways % MOD_VALUE;
// }

int distinctOrderedWays(int n, int x, vector<int> coins) {
    vector<vector<int> > dp(n + 1, vector<int>(x + 1, 0));

    dp[0][0] = 1;
    for (int index = 1; index <= n; index++) {
        for (int sum = 0; sum <= x; sum++) {
            if (sum == 0) {
                dp[index][sum] = 1;
                continue;
            }

            if (index == 0 && sum != 0) {
                dp[index][sum] = 0;
                continue;
            }

            if (index == 0 && sum % coins[index - 1] == 0) {
                dp[index][sum] = 1;
                continue;
            }

            if (index == 0 && sum % coins[index - 1] != 0) {
                dp[index][sum] = 0;
                continue;
            }

            if (sum - coins[index - 1] >= 0) {
                dp[index][sum] += dp[index][sum - coins[index - 1]];
            }

            dp[index][sum] += dp[index - 1][sum];
            dp[index][sum] %= MOD_VALUE;
        }
    }

    return dp[n][x];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << distinctOrderedWays(n, x, coins) << endl;
}