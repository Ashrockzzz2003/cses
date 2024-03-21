/*
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
What is the minimum number of gondolas needed for the children?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

// Greedy approach
ll minGondolasNeeded(vector<ll> &childWeight, ll x) {
    sort(childWeight.begin(), childWeight.end());

    ll i = 0, j = childWeight.size() - 1, count = 0;
    while (i <= j) {
        if (childWeight[i] + childWeight[j] <= x) {
            i++;
            j--;
            count++;
        } else {
            j--;
            count++;
        }
    }

    return count;
}

int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> childWeight(n, 0);

    for (ll i = 0; i < n; i++) {
        cin >> childWeight[i];
    }

    cout << minGondolasNeeded(childWeight, x) << endl;
}