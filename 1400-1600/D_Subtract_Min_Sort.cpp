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
    int mxI = -1;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 1; i<n; i++){
        if(a[i]<a[i-1]){
            cout<<"NO"<<endl;return;
        }else{
            a[i]-=a[i-1];
            a[i-1] = 0;
        }
    }
    cout<<"YES"<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}