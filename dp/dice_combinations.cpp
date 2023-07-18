#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    ll dp[n + 1];
    // dp[i] => number of ways to get sum i using 1, 2, 3, 4, 5, 6

    dp[0] = 1; // 1 way to get sum 0
    for (ll i = 1; i <= n; i++) {
        dp[i] = 0;
        for (ll j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= 1000000007;
            }
        }
    }

    cout << dp[n] << endl;
}