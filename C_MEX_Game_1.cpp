#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n; cin >> n;
    vi cnt(n+2, 0);
		// memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; i++){
			int x; cin >> x;
			cnt[x]++;
		}
		int dif = 0;
		for(int i = 0; i <= n; i++){
			dif += max(0ll, 2 - cnt[i]);
			if(dif >= 2){
				cout << i << "\n";
				break;
		}
	}
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}