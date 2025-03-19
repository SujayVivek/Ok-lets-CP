#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<int> a;
int n;
int rec(int K) {
    if (K <= n) return a[K] ^ a[K - 1];
    int m = K / 2;
    if (m <= n) return a[m];
    return (m % 2 == 0) ? (a[n] ^ rec(m)) : a[n];
}
void Solve() {
    int l, r;
    cin >> n >> l >> r;
    
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1]; 
    }
    if (n % 2 == 0) {
        int extra = a[n / 2] ^ a[n];
        a.push_back(extra);
        n++;
    }

    cout << rec(r) << endl; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
