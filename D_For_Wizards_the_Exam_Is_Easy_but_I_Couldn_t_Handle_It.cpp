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
    int n; cin>>n;
    vi a(n,0);
    for(auto &x: a ) cin>>x;
    pair<int,int> ans;
    ans = {0,0};
    int mx = 0;
    for(int i = 0; i<n-1; i++){
        int del = 0;
        for(int j = i+1; j<n; j++){
            if(a[j]<a[i]) del--;
            else if(a[j]>a[i]) del++;
            if(del<mx){
                mx = del;
                ans = {i,j};
            }
        }
    }
    cout<<ans.first+1<<" "<<ans.second+1<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}