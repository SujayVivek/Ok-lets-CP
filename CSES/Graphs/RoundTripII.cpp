#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"


vvi g;
vi par;
unordered_set<int> whiteSet, graySet, blackSet;
int startNode, endNode;
bool cycle = false;

bool dfs(int node){
    whiteSet.erase(node), graySet.insert(node);
    for(auto x: g[node]){
        if(blackSet.count(x)) continue;

        if(graySet.count(x)){
            startNode = x;
            endNode = node;
            cycle = true;
            return true;
        }

        par[x] = node;
        if(dfs(x)){
            return true;
        }
    }

    graySet.erase(node);
    blackSet.insert(node);
    return false;
}
bool hasCycle(int n){
    for(int i = 1; i<=n; i++){
        whiteSet.insert(i);
    }
    for(int i = 1; i<=n; i++){
        if(whiteSet.count(i) && dfs(i)){
            return true;
        }
    }
    return false;
}
void printCycle(){
    vi Cyc;
    Cyc.push_back(startNode);
    while(endNode!=startNode){
        Cyc.push_back(endNode);
        endNode = par[endNode];
    }
    Cyc.push_back(startNode);
    reverse(Cyc.begin(), Cyc.end());
    cout<<Cyc.size()<<endl;
    for(auto x: Cyc){
        cout<<x<<" ";
    }cout<<endl;
    return;
}
void Solve() {
    int n, m; cin>>n>>m;
    g.resize(n+1);
    par.assign(n+1, -1);
    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
    }
    startNode = -1, endNode = -1;
    if(hasCycle(n)){
        printCycle();
    }else{
        cout<<"IMPOSSIBLE"<<endl;
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