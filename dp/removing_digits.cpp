#include <iostream>
#include <climits>
using namespace std;
#define ll long long

ll minStepsToZero(ll n) {
    ll dp[n + 1];
    dp[0] = 0;

    for(ll i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        ll temp = i;
        while(temp > 0) {
            ll digit = temp % 10;
            temp /= 10;
            if(i - digit >= 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    cout << minStepsToZero(n) << endl;
    return 0;
}