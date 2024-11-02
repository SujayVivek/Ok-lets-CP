#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1001;
vector<int> d(N, N);
vector<vector<int>> dp;  
void calculate() {
    d[1] = 0;
    for (int i = 1; i < N; ++i) {
        for (int x = 1; x <= i; ++x) {
            int j = i + i / x;
            if (j < N) d[j] = min(d[j], d[i] + 1);
        }
    }
}
int calc(int i, int k_left, const vector<int>& b, const vector<int>& c) {
    if (i >= b.size() || k_left < 0) return 0; 
    if (dp[i][k_left] != -1) return dp[i][k_left]; 
    int left = calc(i + 1, k_left, b, c);
    int right = 0;
    if (k_left >= d[b[i]]) {
        right = calc(i + 1, k_left - d[b[i]], b, c) + c[i]; 
    }
    return dp[i][k_left] = max(left, right); 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    calculate();  
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for (int &x : b) cin >> x;
        for (int &x : c) cin >> x;
        int sum = 0;
        for (int x : b) sum += d[x];
        k = min(k, sum);
        dp.assign(n, vector<int>(k + 1, -1));
        cout << calc(0, k, b, c) << '\n';
    }

    return 0;
}
