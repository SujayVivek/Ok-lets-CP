#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void solve() {
    string s;
    cin >> s;
    int n = s.length() / 2;
    int open = n - count(s.begin(), s.end(), '(');
    int close = n - count(s.begin(), s.end(), ')');
    if (open == 0 || close == 0) {
        cout << "YES\n";
        return;
    }
    int cur = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '?') {
            if (cur < open - 1 || cur == open) {
                s[i] = '(';
            } else {
                s[i] = ')';
            }
            cur++;
        }
    }
    int sum = 0;
    for (auto c : s) {
        sum += c == '(' ? 1 : -1;
        if (sum < 0) {
            cout << "YES\n";
            return;
        }
    }
    assert(sum == 0);
    cout << "NO\n";
}
 
int32_t main() {

    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}