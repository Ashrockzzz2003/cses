/*
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    vector< pair<ll, ll> > customers;

    ll arrival, leaving;

    for (ll i = 0; i < n; i++) {
        cin >> arrival >> leaving;
        customers.push_back({arrival, 1});
        customers.push_back({leaving, -1});
    }

    sort(customers.begin(), customers.end());

    ll maxCustomers = 0;
    ll currentCustomers = 0;

    for (ll i = 0; i < customers.size(); i++) {
        currentCustomers += customers[i].second;
        maxCustomers = max(maxCustomers, currentCustomers);
    }

    cout << maxCustomers << endl;
}