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
    int n, c; cin>>n>>c;
    set<int> st;
    int o = 0, e = 0;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        st.insert(x);
        if(x%2)o++;
        else e++;
    }
    int exl = 0;
    for(auto it: st){
        exl += (it + 1 + 1)/2 + (c-it+1);
    }
    cout<<((c+1)*(c+2)/2)-exl+o*(o+1)/2 + e*(e+1)/2<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}