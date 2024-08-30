#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define mod 1000000007

int rec(int sum, vi &dp) {
    if (sum < 0) return 0;   
    if (sum == 0) return 1;  
    if (dp[sum] != -1) return dp[sum];  

    dp[sum] = 0;  
    for (int i = 1; i <= 6; ++i) {
        dp[sum] = (dp[sum] + rec(sum - i, dp)) % mod;
    }

    return dp[sum];
}

void Solve() {
    int n;
    cin >> n;
    vi dp(n + 1, -1);  // Memoization table initialized with -1
    cout << rec(n, dp) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
