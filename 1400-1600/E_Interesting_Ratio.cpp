#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int MAXN = 10000001;
bool prime[MAXN];
void seive(){
    for (int i = 0; i < MAXN; i++) prime[i] = 1;
    prime[0] = prime[1] = 0;
	for (int i = 2; i * i < MAXN; i++) {
	    if (!prime[i]) continue;
	    for (int j = i * i; j < MAXN; j += i) 
            prime[j] = 0;
	}
}
void Solve() {
    int n, ans = 0;
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            ans += n / i;
        }
    }
    
    cout << ans << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    seive();
    while (tt_--) {
        Solve();
    }
    return 0;
}