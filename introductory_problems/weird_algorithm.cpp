#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    cout << n << " ";

    while(n != 1) {
        n % 2 == 0 ? n /= 2 : n = n*3 + 1;
        cout << n << " ";
    }
}