#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    // total available choices -> 1st in (n*n) and 2nd in (n*n - 1)
    // attack positions -> 2 times no of 2*3 and 3*2 sub matrices possible

    for(ll i = 1; i <= n; i++) {
        cout << ((i*i)*(i*i - 1)/2) - (2*2*(i-1)*(i-2)) << endl;
    }
}