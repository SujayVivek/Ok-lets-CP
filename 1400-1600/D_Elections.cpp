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
    int n, c; cin>>n>>c;
    vi a(n,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int mxEle = *max_element(a.begin()+1, a.end());
    int mx = max(a[0]+c, mxEle);
    int mxI = mx==a[0]+c? 0: find(a.begin()+1, a.end(), mxEle)- a.begin();
    int sum = c;
    for(int i = 0; i<n; sum+= a[i], ++i){
        if(i==mxI){
            cout<<0<<" ";
        }else if(a[i] + sum >= mxEle){
            cout<<i<<" ";
        }else{
            cout<<i+1<<" ";
        }
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}