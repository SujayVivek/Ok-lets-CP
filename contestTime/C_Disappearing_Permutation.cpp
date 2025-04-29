#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
vi v;
set<int> st;
map<int,int> mpp;
int calc(int pt){
    int cnt = 0;
    while(st.count(pt)==0){
        cnt++; st.insert(pt);
        pt = mpp[pt];
    }
    return cnt;
}
void Solve() {
    int n; cin>>n;
    v.assign(n+1, 0);
    for(int i = 0; i<n; i++){
        cin>>v[i+1];
        mpp[v[i+1]] = i+1;
    }
    st.clear();int cnt = 0;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        if(st.count(x)) {cout<<cnt<<" ";}
        else {cnt+= calc(x); cout<<cnt<<" ";}
        st.insert(x);
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}