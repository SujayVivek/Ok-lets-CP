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
    int X, Y, ax, ay, bx, by; cin>>X>>Y>>ax>>ay>>bx>>by;
    int x, y, t; cin>>x>>y>>t;

    vi xPos, yPos;
    xPos.push_back(X), yPos.push_back(Y);
    int lim = (1LL<<56)-1;
	while ((lim - bx) / ax >= xPos.back() && (lim - by) / ay >= yPos.back()) {
		xPos.push_back(ax * xPos.back() + bx); yPos.push_back(ay * yPos.back() + by);
	}
    int n = xPos.size();
    //iterating thru all L to R ranges
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int LRlen = abs(xPos[i]-xPos[j]) + abs(yPos[i]-yPos[j]);
            int stLenR  = abs(x-xPos[j]) + abs(y-yPos[j]); //start to Right length
            int stLenL = abs(x-xPos[i]) + abs(y-yPos[i]);
            if((LRlen + stLenR)<=t || (LRlen + stLenL)<=t) ans = max(ans, j-i+1);
        }   
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}