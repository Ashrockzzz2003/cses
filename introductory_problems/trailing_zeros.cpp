/*
Our task is to calculate the number of trailing zeros in the factorial n!.
For example, 20!=2432902008176640000 and it has 4 trailing zeros.
*/

#include <iostream>
using namespace std;
#define ll long long

int numberOfTrailingZeros(ll n) {
    /*
    Idea
    - The number of trailing zeros in n! is the number of 10s in the prime factorization of n!.
    - The number of 10s in the prime factorization is the same as the number of 5s.
    - So, we need to count the number of 5s in the prime factorization of n!.
    */
    ll count = 0;
    for (ll i = 5; n / i > 0; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    ll n;
    cin >> n;

    cout << numberOfTrailingZeros(n) << endl;

}