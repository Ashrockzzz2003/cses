#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;

    if (sum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        sum /= 2;

        ll set_sum = 0;

        vector<ll> set_1, set_2;

        set_1.push_back(n);

        for(ll i = n - 1; i >= 1; i--) {
            if (set_sum + i <= sum) {
                set_2.push_back(i);
                set_sum += i;
            } else {
                set_1.push_back(i);
            }
        }

        cout << "YES" << endl;

        cout << set_1.size() << endl;
        for(ll i = 0; i < set_1.size(); i++) {
            cout << set_1[i] << " ";
        }
        cout << endl;

        cout << set_2.size() << endl;
        for(ll i = 0; i < set_2.size(); i++) {
            cout << set_2[i] << " ";
        }
        cout << endl;
    }
}