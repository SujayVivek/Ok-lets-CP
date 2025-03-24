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
    vi a(n,0); set<int> st; 
    for(int i = 0; i<n; i++){
        cin>>a[i];
        st.insert(a[i]);
    } int T = 0; bool ok = false;
    vector<pair<int,int>>vpi;
    if(n%2==0){
        for(int i = n-2; i>=0; i-=2){
            if(a[i] == 0 || a[i+1] ==0){
                vpi.push_back({i+1, i+2});
            }
        }
         T = vpi.size();
    }else{
        for(int i = n-2; i>0; i-=2){
            if(a[i] == 0 || a[i+1] == 0){
                vpi.push_back({i+1, i+2});
            }
        }  T = vpi.size();
        if(a[0]==0){
            vpi.push_back({1,2}); ok = true;
        }
    }T+= (ok)?1:0;
    vpi.push_back({1,n-T});
    cout<<vpi.size()<<endl;
    for(auto it: vpi){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}