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
    int n; cin>>n;int X = -1;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        if(x!=i){
            if(X!=-1) X&=x;
            else X = x;
        }
    }
    cout<<X<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}