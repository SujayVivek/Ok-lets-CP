#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

long long qpow(int x,int y){
	if (!y) return 1;
	long long a=qpow(x,y/2);
	if (y%2) return a*a%mod*x%mod; else
		return a*a%mod; 
}
void Solve() {
    int l, r, k; cin>>l>>r>>k;
    cout<< (qpow(9/k + 1, r) - qpow(9/k + 1, l) + mod)%mod;
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}