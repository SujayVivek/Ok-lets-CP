#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005; // Adjust this based on the problem constraints

int cnt[MAXN]; // To store the count of multiples

int main() {
    int t;cin>>t;
    while(t--){
        int n, m;
    cin >> n >> m;

    // Precompute the count of multiples
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            cnt[j]++;
        }
    }

    long long ans = 0;
    for (int a = 1; a <= n; a++) {
        ans += cnt[a];
    }

    cout << ans << endl;
    }
    
    return 0;
}
