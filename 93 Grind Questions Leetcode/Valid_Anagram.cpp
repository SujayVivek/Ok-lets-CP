#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    int map[26] = {0}; // Initialize map array for character counting

    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - 'a';
        map[idx]++;
    }

    for (int j = 0; j < t.size(); j++) {
        int idx = t[j] - 'a';
        map[idx]--;
    }

    for (int k = 0; k < 26; k++) {
        if (map[k] != 0)
            return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, u;
        cin >> s >> u; // Changed the variable name from 't' to 'u'
        cout << isAnagram(s, u) << endl; // Added endl for better output formatting
    }
    return 0;
}
