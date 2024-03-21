/*
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

// Greedy approach
ll maxAllocationPossible(vector<ll> &applicantData, vector<ll> &apartmentData, ll k) {
    sort(applicantData.begin(), applicantData.end());
    sort(apartmentData.begin(), apartmentData.end());

    ll i = 0, j = 0, count = 0;
    while (i < applicantData.size() && j < apartmentData.size()) {
        if (abs(applicantData[i] - apartmentData[j]) <= k) {
            i++;
            j++;
            count++;
        } else if (applicantData[i] < apartmentData[j]) {
            i++;
        } else {
            j++;
        }
    }

    return count;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> applicantData(n, 0), apartmentData(m, 0);

    for (ll i = 0; i < n; i++) {
        cin >> applicantData[i];
    }

    for (ll i = 0; i < m; i++) {
        cin >> apartmentData[i];
    }

    cout << maxAllocationPossible(applicantData, apartmentData, k) << endl;
}