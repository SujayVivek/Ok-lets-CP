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
    vi a;
    for(int i = 0; i<n; i++){
        int x; cin>>x; 
        a.push_back(x);
        mpp[x]++;
    }
    int mx_i =-1 , mx = 0;
    for(int i = 0; i<n; i++){
        if(mpp[a[i]] == 1){
            if(a[i]>mx){
                mx = a[i];
                mx_i = i+1;
            }
        }   
    }
    cout<<mx_i<<endl;
}
int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}