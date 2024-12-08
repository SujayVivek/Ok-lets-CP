#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    vi hash(n, 0);
    for (int i = 0; i < m; i++) {
        int l;
        cin >> l;
        hash[l-1]++;  // Mark the index where replacements are allowed
    }
    
    string b;
    cin >> b;
    sort(b.begin(), b.end()); // Sort `b` for lexicographical order replacements
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (hash[i] > 0 && j < b.length()) { // Replace only if marked and `b` has characters left
            s[i] = b[j];
            j++;
        }
    }
    cout << s << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
