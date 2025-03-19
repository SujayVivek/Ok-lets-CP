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
    int n, k; cin>>n>>k;
    if(k%2==1){
        for(int i = 1; i<=n-1; i++){
            cout<<n<<" ";
        }cout<<n-1<<" "<<endl;return;
    }else{
        for(int i = 1; i<=n-2; i++){
            cout<<n-1<<" ";
        }cout<<n<<" "<<n-1<<" "<<endl;return;
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