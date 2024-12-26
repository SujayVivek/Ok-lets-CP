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
    int n, d; cin>>n>>d;
    vvi v(n, vi(2,0));
    for(int i = 0; i<n; i++){
        int x, y; cin>>x>>y;
        v[i] = {x,y};
    }
    sort(v.begin(), v.end());
    int i = 0, j = 0;
    int ans = 0, sumFact = 0;
    while(i<n && j<n){
        // cout<<sumFact<<" hi"<<endl;
        if(v[j][0]-v[i][0]<d){
            sumFact+=v[j][1];
            j++;
        }else{
            ans = max(ans, sumFact);
            sumFact-=v[i][1];
            i++; 
        }
    }
    ans = max(ans, sumFact);
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