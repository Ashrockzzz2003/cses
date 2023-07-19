#include <iostream>
#include <vector>
using namespace std;

#define ll long long

// 3 2 5 1 7 = +1
// 3 3 5 1 7 = +0
// 3 3 5 1 7 = +0
// 3 3 5 5 7 = +4
// 3 3 5 5 7 = +0

void solve() {
    ll n;
    cin >> n;

    vector<ll> arr(n);

    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll count = 0;

    for(int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            count += arr[i - 1] - arr[i];
            arr[i] += (arr[i - 1] - arr[i]);
        }
    }

    cout << count << endl;
}

int main() {
    solve();
    return 0;
}