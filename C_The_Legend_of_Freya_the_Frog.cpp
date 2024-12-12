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
    int X,Y,K;
		cin>>X>>Y>>K;
		X=(X+K-1)/K;
		Y=(Y+K-1)/K;
		if(X>Y)cout<<X+X-1<<"\n";
		else cout<<Y+Y<<"\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}