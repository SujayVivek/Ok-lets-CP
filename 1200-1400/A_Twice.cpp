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
    map<int,int>mpp;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        mpp[x]++;
    }
    int Sum = 0;
    for(auto it: mpp){
        Sum+= it.second/2;
    }
    cout<<Sum<<endl;
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