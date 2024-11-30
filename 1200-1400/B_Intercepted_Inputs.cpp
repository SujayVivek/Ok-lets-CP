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
    int k; cin>>k;
    map<int,int> mpp;
    vi a(k,0);
    for(auto &x: a) cin>>x;
    for(int i = 0; i<k; i++){
        int x = a[i];
        if(mpp[x]){
            cout<<x<<" "<<(k-2)/x<<endl;
            break;
        }
        if((k-2)%x==0){
            mpp[(k-2)/x]++;
        }
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