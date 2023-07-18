#include <iostream>
using namespace std;
#define ll long long

void solve() {
    string seq;
    cin >> seq;

    if(seq.length() == 1) {
        cout << 1 << endl;
        return;
    }

    ll max_count = 0;

    for(ll i = 0; i < seq.length() - 1; i++) {
        ll count = 1;
        while(seq[i] == seq[i + 1]) {
            count++;
            i++;
        }
        max_count = max(max_count, count);
    }

    cout << max_count << endl;
}

int main() {
    solve();
}