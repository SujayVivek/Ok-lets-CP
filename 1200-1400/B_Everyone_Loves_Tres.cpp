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
    if(n==1 || n==3) {cout<<-1<<endl; return;}
    if(n%2==0){
        for(int i = 0; i<n; i++){
            if(i<=n-3) cout<<3;
            else cout<<6;
        }cout<<endl;
    }else{
        for(int i = 0; i<n; i++){
            if(i<n-4) cout<<3; 
        }
        cout<<6366<<endl;
        return;
    }
    return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}