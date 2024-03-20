/*
Given a string, your task is to generate all different strings that can be created using its characters.
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<string> all_permutations;

// Backtracking Approach
void generate_permutations(string s, int l, int r) {
    if (l == r) {
        all_permutations.insert(s);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        generate_permutations(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

int main() {
    string s;
    cin >> s;
    generate_permutations(s, 0, s.size() - 1);
    cout << all_permutations.size() << endl;

    vector<string> all_permutations_vector(all_permutations.begin(), all_permutations.end());

    sort(all_permutations_vector.begin(), all_permutations_vector.end());

    for (auto permutation : all_permutations_vector) {
        cout << permutation << endl;
    }

    return 0;
}
