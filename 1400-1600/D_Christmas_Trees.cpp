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
    queue<int> q;
    map<int,int> Trees;
    map<int,int> dist;
    for(int i = 0; i<n; i++){
        int x; cin>>x; q.push(x);
        Trees[x]++;
    }
    vi ans;
    int D = 0;
    
    while(!q.empty()){
        int Top = q.front();
        q.pop();
        if(!Trees[Top+1]){
            Trees[Top+1]++;
            q.push(Top+1);
            ans.push_back(Top+1);
            dist[Top + 1]+= dist[Top]+1;
            D+= dist[Top + 1];
        }
        if(ans.size()>=m) break;
        if(!Trees[Top-1]){
            Trees[Top-1]++;
            q.push(Top-1);
            ans.push_back(Top-1);
            dist[Top-1]+= dist[Top] + 1;
            D+= dist[Top-1];
        }
        if(ans.size()>=m) break;
    }
    cout<<D<<endl;
    for(auto x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}