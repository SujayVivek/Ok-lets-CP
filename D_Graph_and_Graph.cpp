#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
vvi adj(1000, vi(1000, 1e9));
set<int>Near_points;
void multibfs(int s1, int s2, vvi &g1, vvi &g2){
    queue<int> q1, q2;
    q1.push(s1), q2.push(s2);
    while(!q1.empty() && !q1.empty()){
        int top1 = q1.front(); q1.pop();
        int top2 = q2.front(); q2.pop();
        for(auto A: g1[top1]){
            for(auto B: g2[top2]){
                if(adj[A][B]> abs(A-B)+adj[top1][top2]){
                    adj[A][B] = abs(A-B) + adj[top1][top2];
                }
                q2.push(B);
            }
            q1.push(A);
        }
    }
}
void Solve() {
    int n, s1, s2; cin>>n>>s1>>s2;
    int m1; cin>>m1;
    set<pair<int,int>> st;
    vvi g1(n+1), g2(n+1);
    for(int i = 0; i<m1; i++){
        int a, b; cin>>a>>b;
        st.insert({a, b}); st.insert({b,a});
        g1[a].push_back(b), g1[b].push_back(a);
    }
    Near_points.clear();
    int m2; cin>>m2;
    for(int i = 0; i<m2; i++){
        int a, b; cin>>a>>b;
        g2[a].push_back(b), g2[b].push_back(a);
        if(st.find(make_pair(a, b))!=st.end()){
            Near_points.insert(a), Near_points.insert(b);
        }
    }
    if(Near_points.size()==0){
        cout<<-1<<endl;return;
    }
    adj[s1][s2] = 0;
    multibfs(s1, s2, g1, g2);
    int ans = 1e9;
    for(auto it: Near_points){
        ans = min(adj[it][it], ans);
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}