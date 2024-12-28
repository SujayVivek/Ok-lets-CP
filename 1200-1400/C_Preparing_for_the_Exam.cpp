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
    int n, m, k; cin>>n>>m>>k;
    vi a(m,0), q(k,0);
    map<int,int> mpp;
    for(int i = 0; i<m; i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    for(int i = 0; i<k; i++){
        cin>>q[i];
        mpp[q[i]]--;
    }
    if(n==k || n<k){
        for(int i = 0; i<m; i++){
            cout<<1;
        }cout<<endl;return;
    }else if(n-k>=2){
        for(int i = 0; i<m; i++)
        cout<<0;
        cout<<endl;return;
    }else{
        for(int i = 0; i<m; i++){
            if(mpp[a[i]]) cout<<1;
            else cout<<0;
        }cout<<endl;return;
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