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
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    bool ok = false;
    int j = n-2, i = n-1;
    int most_min_change = 1e18;
    map<int,int>mpp;
    while(j>=0){
        if(a[j]>a[i]){
            a[j]++;
            mpp[j]++;
            most_min_change = min(most_min_change, a[j]);
            j--;
        }else{
            i = j;
            j--;
        }
    }
    for(int i = n-1; i>=0; i--){
        if(mpp[i]==0){
            if(a[i]>most_min_change) a[i]++;
        }
    }
    sort(a.begin(), a.end());
    for(auto x: a){
        cout<<x<<" ";
    }cout<<endl;
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