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
    vi a(n,0);
    int S = 0;
    map<int,int> mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        S+= a[i];
        mpp[a[i]]++;
    }
    if((((S/n) == 1) && ((n-mpp[1])*1 + 2*(mpp[1]))>S) || n==1){
        cout<<"NO"<<endl; return;
    }
    cout<<"YES"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}