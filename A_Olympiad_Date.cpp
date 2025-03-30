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
    int n;
    cin >> n;
    
    int cnt[10] {};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        
        if (cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1 && ans == 0) {
            ans = i;
        }
    }
    cout << ans << "\n";
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
