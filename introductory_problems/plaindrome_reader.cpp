#include <iostream>
#include <vector>
using namespace std;

string makePalindrome(string s) {
    if (s.length() <= 1) {
        return s;
    }

    vector<int> freq(26, 0);
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'A']++;
    }

    if (s.length() % 2 == 0) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                return "NO SOLUTION";
            }
        }
        s = "";
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq[i]/2; j++) {
                s += (char)('A' + i);
            }
        }
        string t = s;
        reverse(t.begin(), t.end());
        return s + t;
    } else {
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                odd++;
            }
        }
        if (odd != 1) {
            return "NO SOLUTION";
        }
        s = "";
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq[i]/2; j++) {
                s += (char)('A' + i);
            }
        }
        string t = s;
        reverse(t.begin(), t.end());
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                s += (char)('A' + i);
            }
        }
        return s + t;
    }
}

int main() {    
    string s;
    cin >> s;

    cout << makePalindrome(s) << endl;
}