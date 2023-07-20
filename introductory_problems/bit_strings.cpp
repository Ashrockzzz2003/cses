#include <iostream>
using namespace std;
#define ll long long

const int MODULO = 1000000007;

ll fast_power(ll n) {
    if (n == 0) {
        return 1;
    }

    ll result = fast_power(n / 2);
    result = (result * result) % MODULO;

    if (n % 2 == 1) {
        result = (result * 2) % MODULO;
    }

    return result;
}

int main() {
    ll n;
    cin >> n;

    cout << fast_power(n) << endl;
}