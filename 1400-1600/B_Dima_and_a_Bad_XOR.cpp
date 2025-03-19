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
    vector<set<int>>vs(n); vvi grid(n, vi(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
            vs[i].insert(grid[i][j]);
        }
    }
    int XOR = 0;
    map<int,int> Row; vector<pair<int,int>>ans; vi vv;
    for(int i = 0; i<n; i++){
        if(vs[i].size() == 1) {XOR^=*vs[i].begin(); Row[i] = 1; ans.push_back({i+1,1});}
        else vv.push_back(i);
    }
    if(XOR!=0 && vv.size() == 0){
        cout<<"TAK"<<endl;
        sort(ans.begin(), ans.end());
        for(auto it: ans)cout<<it.second<<" ";
        cout<<endl;
        return;
    }else if(XOR == 0 && vv.size()==0){
        cout<<"NIE"<<endl;return;
    }
    for(int i = 0; i<vv.size()-1; i++){
        XOR^=grid[vv[i]][0]; ans.push_back({vv[i]+1, 1});
    }
    bool ok = false;
    for(int i = 0; i<m; i++){
        if((XOR^grid[vv[vv.size()-1]][i])!=0){
            XOR^=grid[vv[vv.size()-1]][i];
            ans.push_back({vv[vv.size()-1]+1, i+1}); ok = true;
            break;
        }
    }
    if(ok){
        cout<<"TAK"<<endl;
        sort(ans.begin(), ans.end());
        for(auto it: ans)cout<<it.second<<" ";
        cout<<endl;
        return;
    }else{
        cout<<"NIE"<<endl;return;
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}