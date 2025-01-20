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
    vi hash(n*m, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int x; cin>>x;
            hash[x] = i+1;
        }
    }
    vi Order;
    set<int> st;
    for(int i = 0; i<n; i++){
        st.insert(hash[i]);
        Order.push_back(hash[i]);
    }
    if(st.size()!=n){
        cout<<-1<<endl;return;
    }
    for(int i = n, j = 0; i<n*m; i++, j++){
        if(hash[i]!=Order[j%n]){
            cout<<-1<<endl;return;
        }
    }
    for(auto &x: Order)cout<<x<<" ";
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