#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define endl "\n"

// Function to recursively calculate the number of ways
int calc(int i, int sum, int target, vector<vector<int>>& dp) {
    if (sum > target) return 0; // Invalid sum
    if (i == 0) return (sum == 0); // Base case: Only one way to make sum=0 with 0 elements

    if (dp[i][sum] != -1) return dp[i][sum]; // Memoized result

    // Include the current number or skip it
    int exclude = calc(i - 1, sum, target, dp);      // Exclude `i`
    int include = calc(i - 1, sum - i, target, dp);  // Include `i`

    return dp[i][sum] = (exclude + include) % mod; // Store and return result
}

void Solve() {
    int n; cin >> n;
    int total_sum = n * (n + 1) / 2;

    if (total_sum % 2 == 1) { // If the total sum is odd, equal partition is not possible
        cout << 0 << endl;
        return;
    }

    int target = total_sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); // Initialize memoization table

    // Solve the problem recursively
    cout << calc(n - 1, target, target, dp) << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
