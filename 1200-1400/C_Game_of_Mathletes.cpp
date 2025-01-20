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
    multiset<int> Set;
    for(int i = 0; i<n; i++){
        int X; cin>>X;
        if(mpp[X]){
            Set.insert(k-X);
            Set.insert(X);
            mpp[X]--;
        }else{
            mpp[k-X]++;
        }
    }
    cout<<Set.size()/2<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}