/*
Consider an infinite string that consists of all positive integers in increasing order:
12345678910111213141516171819202122232425...

Your task is to process q queries of the form: what is the digit at position k in the string?
*/

#include <iostream>
using namespace std;
#define ll long long

int digitInPosition(ll k) {
    ll digits = 1, start = 1;
    while (k > 9 * digits * start) {
        // cout << "k: " << k << " digits: " << digits << " start: " << start << endl;
        k -= 9 * digits * start;
        digits++;
        start *= 10;
    }
    // cout << "k: " << k << " digits: " << digits << " start: " << start << endl;
    ll number = start + (k - 1) / digits;
    // cout << "number: " << number << endl;
    return to_string(number)[(k - 1) % digits] - '0'; // The digit at position k in the infinitely long string is the (k-1)%digits-th digit of the number.
}

int main() {
    ll q;
    cin >> q;

    while(q--) {
        ll k;
        cin >> k;

        cout << digitInPosition(k) << endl;
    }
}