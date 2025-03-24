#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vector<vector<int>> adj;
vector<int> color; 

pair<int,int> dfs(int node) {
    pair<int,int> cnt = {0,0};
    stack<int> st;
    st.push(node);
    color[node] = 0;
    while(!st.empty()){
        int cur = st.top(); st.pop();
        cnt.first += (color[cur] == 0);
        cnt.second += (color[cur] == 1);
        for(auto nxt: adj[cur]){
            if(color[nxt] == -1){
                color[nxt] = color[cur] ^ 1;
                st.push(nxt);
            }
        }
    }
    return cnt;
}

void Solve() {
    int N, M;
    cin >> N >> M;
    adj.assign(N+1, vector<int>());
    color.assign(N+1, -1);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int,int>> comps;
    for (int i = 1; i <= N; i++){
        if (color[i] == -1) {
            pair<int,int> cnt = dfs(i);
            comps.push_back(cnt);
        }
    }
    vector<bool> dp(N+1, false);
    dp[0] = true;
    for(auto &comp: comps) {
        int a = comp.first, b = comp.second;
        vector<bool> next(N+1, false);
        for (int x = 0; x <= N; x++){
            if(dp[x]){
                if(x+a <= N) next[x+a] = true;
                if(x+b <= N) next[x+b] = true;
            }
        }
        dp = move(next);
    }
    int best = 0;
    for (int x = 0; x <= N; x++){
        if(dp[x]){
            best = max(best, x*(N-x));
        }
    }
    int remaining = best - M;
    if(remaining % 2 == 1) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
