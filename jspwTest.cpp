#include<bits/stdc++.h>
using namespace std;

int solve(int i, int n, vector<int>& a, vector<int>& dp) {
    if (i >= n) return INT_MAX; // if index goes out of bounds, return a large value
    if (i == n-1) return 1; // base case, reached the last element
    if (dp[i] != -1) return dp[i]; // return the stored value if already computed

    int jump = a[i];
    int min_steps = solve(i + 1, n, a, dp) + 1; // option 1: move to the next element
    
    // option 2: jump to the index based on the value of a[i]
    if (i + jump + 1 <= n) 
        min_steps = min(min_steps, solve(i + jump + 1, n, a, dp));

return dp[i] = min_steps; // store the result in
