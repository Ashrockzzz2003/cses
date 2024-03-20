/*
There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal. Output the minimal difference.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll minimizeDifferenceandDivide(ll i, vector<ll> p, ll left_sum, ll right_sum) {
    if (i == p.size()) {
        return abs(left_sum - right_sum);
    }

    return min(minimizeDifferenceandDivide(i + 1, p, left_sum + p[i], right_sum), minimizeDifferenceandDivide(i + 1, p, left_sum, right_sum + p[i]));
}

int main() {
    ll n;
    cin >> n;

    vector<ll> p(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << minimizeDifferenceandDivide(0, p, 0, 0) << endl;
}