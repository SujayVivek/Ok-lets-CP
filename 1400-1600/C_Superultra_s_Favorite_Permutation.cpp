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
    if(n<=4){
        cout<<-1<<endl;
        return;
    }
    for(int i = 1; i<=n; i+=2){
        if(i!=5) cout<<i<<" ";
    }
    cout<<5<<" "<<4<<" ";
    for(int i = 2; i<=n; i+=2){
        if(i!=4) cout<<i<<" ";
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