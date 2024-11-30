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
    for(int i = 0; i<n-2; i++){
        cout<<i+1<<" "<<i+1<<endl;
    }
    cout<<n-1<<" "<<n<<endl;
    cout<<n<<" "<<n<<endl;
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