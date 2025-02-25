#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int vote(char a, char b, char c) {
    return (a == 'A') + (b == 'A') + (c == 'A') >= 2;
}
 
void Solve() {
    int n;
    cin >> n;
    
    string S[2];
    cin >> S[0] >> S[1];
    
    vector<int> f(n + 1), g(n + 1), h(n + 1);
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            f[i + 3] = max(f[i + 3], f[i] + vote(S[0][i], S[0][i + 1], S[0][i + 2]) + vote(S[1][i], S[1][i + 1], S[1][i + 2]));
            g[i + 1] = max(g[i + 1], f[i] + vote(S[0][i], S[0][i + 1], S[1][i]));
            h[i + 1] = max(h[i + 1], f[i] + vote(S[1][i], S[1][i + 1], S[0][i]));
        }
        if (i % 3 == 1) {
            if (i + 3 < n) {
                g[i + 3] = max(g[i + 3], g[i] + vote(S[0][i + 1], S[0][i + 2], S[0][i + 3]) + vote(S[1][i], S[1][i + 1], S[1][i + 2]));
                h[i + 3] = max(h[i + 3], h[i] + vote(S[1][i + 1], S[1][i + 2], S[1][i + 3]) + vote(S[0][i], S[0][i + 1], S[0][i + 2]));
            }
            f[i + 2] = max(f[i + 2], g[i] + vote(S[0][i + 1], S[1][i], S[1][i + 1]));
            f[i + 2] = max(f[i + 2], h[i] + vote(S[1][i + 1], S[0][i], S[0][i + 1]));
        }
    }
    
    cout << f[n] << "\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}