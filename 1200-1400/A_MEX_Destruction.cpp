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
    map<int,int> mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    if(mpp[0]==n){
        cout<<0<<endl;return;
    }
    if(mpp[0]==0){
        cout<<1<<endl;return;
    }
    int j = 0, k = n-1;
    while(a[j]==0){
        j++;
    }
    while(a[k]==0){
        k--;
    }
    for(int i = j; i<=k; i++){
        if(a[i]==0){
            cout<<2<<endl;return;
        }
    }
    cout<<1<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}