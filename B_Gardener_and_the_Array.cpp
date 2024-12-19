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
        int n, k;
		map<int,int>a;
		cin>>n;
		vector<vector<int> >g(n);
		for (int i=0; i<n; i++){
			cin>>k;
            g[i].resize(k);
			for (int j=0; j<k; j++){
                int p;cin>>p;
                g[i][j]=p;a[p]++;
            }
		}
		bool ans=false;
		for (int i=0; i<n; i++){bool ok=true;
			for (auto j: g[i]) if(a[j]<2) ok=false;
			ans|=ok;
		}
		if (ans)cout<<"Yes\n"; else cout<<"No\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}