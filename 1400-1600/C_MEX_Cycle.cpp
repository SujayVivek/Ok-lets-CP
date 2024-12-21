#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
int n, x, y; 
int Mex(set<int> s){
    int mx = 0;
    for(int i = 0; i<n; i++){
        if(s.find(mx)==s.end()){
            break;
        }
        mx++;
    }
    return mx;
}

void Solve() {
    cin>>n>>x>>y; x--, y--;
    vi vis(n,-1);
    vector<set<int>> g(n);
    g[x].insert(y);
    g[y].insert(x);
    for(int i = 0; i<n; i++){
        int a = i+1, b = n+a-2;
        g[i].insert(a%n);
        g[i].insert(b%n);
    }
    set<int> search;
    vi ans(n);
    for(int i = 0; i<n; i++){
        search.clear();
        for(auto v: g[i]){
            if(vis[v]!=-1){
                search.insert(vis[v]);
            }
        }
        vis[i] =  Mex(search);
    }
    for(auto &x: vis)cout<<x<<" ";
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