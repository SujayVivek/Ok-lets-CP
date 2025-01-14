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
    map<int,int> mpp;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        mpp[x]++;
    }
    vvi v;
    for(auto it: mpp){
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end());
    int N = v.size();
    int i = 0;
    while(k){
        if(v[i][0]<=k){
            k-=v[i][0];
            i++;
        }else{
            break;
        }
    }
    cout<< max(v.size()-i,1ll)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}