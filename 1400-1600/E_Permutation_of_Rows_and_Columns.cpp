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
    int n, m; cin>>n>>m;
    vi rows(n*m+1, 0), cols(n*m+1, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int x; cin>>x;
            rows[x] = i;
            cols[x] = j;
        }
    }
    map<pair<int,int>,int> rowCtr, colCtr;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int x; cin>>x;
            rowCtr[make_pair(i, rows[x])]++;
            colCtr[make_pair(j,cols[x])]++;
        }
    }
    for(auto it: rowCtr){
        if(it.second!=m){
            cout<<"NO"<<endl;return;
        }
    }
    for(auto it: colCtr){
        if(it.second!=n){
            cout<<"NO"<<endl;return;
        }
    }
    cout<<"YES"<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}