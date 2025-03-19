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
    int n, x; cin>>n>>x;
    int S = 0;
    for(int i = 0; i<n; i++){
        int X; cin>>X;
        S+= X;
    }
    if(S/n == x && S%n == 0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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