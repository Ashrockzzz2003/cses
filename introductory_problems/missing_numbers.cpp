#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    ll sum = 0;

    for (ll i = 1; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
    }

    cout << n*(n+1)/2 - sum << endl;
}