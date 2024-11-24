#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

#define int long long

int M = 1e9 + 7;

int pow2(int x, int n) {
    x %= M;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    int p = pow2(x * x, n / 2);
    if (n % 2)
        return p * x % M;
    else
        return p;
}

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<pair<int, int>> stp;
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int c = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            c++;
        }
        ans[i] = ans[i - 1];
        while (!stp.empty()) { 
            if (c > 32 || stp.top().first < a[i] * (1LL << c)) {
                int val = stp.top().first, p = stp.top().second;
                ans[i] = (ans[i] - val * pow2(2, p) % M + M) % M;
                ans[i] = (ans[i] + val);
                c += p;
                stp.pop();
            } 
            else break;
        }
        stp.push({a[i], c});
        ans[i] = (ans[i] + a[i] * pow2(2, c) % M) % M;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}