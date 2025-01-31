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
    map<int,set<int>>mpst;
    map<int,set<int>>stmp;
    set<int> points;
    for(int i = 0; i<n; i++){
        int A; cin>>A;
        for(int j = 0; j<A; j++){
            int B; cin>>B;
            mpst[B].insert(i+1);
            stmp[i+1].insert(B);
            points.insert(B);
        }
    }
    // int mn = 1e18, point = -1;
    // for(auto it: mpst){
    //     if(it.second.size()<mn){
    //         mn = it.second.size();
    //     }
    // }
    // for(auto it: mpst){
    //     if(it.second.size() == mn){
    //         points.push_back(it.first);
    //     }
    // }
    // cout<<point<<" HYI"<<endl;
    int ans = 0;
    for(auto point: points){
        set<int> st;
        for (auto it : stmp)
        {
            if (it.second.find(point) == it.second.end())
                for (auto pt : it.second)
                {
                    st.insert(pt);
                }
        }
        ans = max(ans, 1LL*st.size());
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