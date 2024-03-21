/*
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;

    ll ticket, maxPrice;

    multiset<ll> tickets;

    for (ll i = 0; i < n; i++) {
        cin >> ticket;
        tickets.insert(ticket);
    }

    for (ll i = 0; i < m; i++) {
        cin >> maxPrice;

        auto it = tickets.upper_bound(maxPrice);

        if (it == tickets.begin()) {
            cout << -1 << endl;
        } else {
            cout << *(--it) << endl;
            tickets.erase(it);
        }
    }

}