/*
You are given a list of n integers, and your task is to calculate the number of distinct values in the list.
*/

#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll distinct_numbers(vector<ll> &arr) {
    sort(arr.begin(), arr.end());
    ll count = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1]) {
            count++;
        }
    }
    return count;
}

// TLE
// ll distinct_numbers_with_map(vector<ll> &arr) { 
//     unordered_map<ll, ll> mp;
//     for (ll i = 0; i < arr.size(); i++) {
//         mp[arr[i]]++;
//     }
//     return mp.size();
// }

int main() {
    ll n;
    cin >> n;

    vector<ll> arr(n, 0);

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << distinct_numbers(arr) << endl;
}