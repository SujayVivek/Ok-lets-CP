#include<bits/stdc++.h>
using namespace std;

int solve(int i, int n, vector<int>& a, vector<int>& dp) {
    if (i == n-1) return 1; 
    if(i==n)return 0;
    if (dp[i] != -1) return dp[i]; 

    int min_steps = solve(i + 1, n, a, dp) + 1; 
    if (i + 1 + a[i] <= n) 
        min_steps = min(min_steps, solve(i + 1 + a[i], n, a, dp));

    return dp[i] = min_steps; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), dp(n, -1); // initialize dp array with -1

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        int result = solve(0, n, a, dp);
        cout << result << endl;
    }
    return 0;
}
