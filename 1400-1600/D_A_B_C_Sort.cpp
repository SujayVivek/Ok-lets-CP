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
    for(auto &x: a)cin>>x;
    vi b = a;
    sort(b.begin(), b.end());
    if(n==1){
        cout<<"YES"<<endl;return;
    }
    for(int i = n-2; i>=0; i-=2){
        int x = a[i], y = a[i+1];
        if(x>y)swap(x,y);
        if(x != b[i] || y != b[i+1]){
            cout<<"NO"<<endl;return;
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