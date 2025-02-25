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
    map<int,int>mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    vi unGroup;
    for(auto it: mpp){
        if(it.second%2){
            unGroup.push_back(it.first);
        }
    }
    if(unGroup.size() == 0){cout<<"YES"<<endl;return;}
    sort(a.begin(),a.end());
    for(auto it: mpp){
        if(it.second>=3){
            mpp[it.first + 1] += (it.second-2);
            mpp[it.first] = 2;
        }
    }
    for(auto it: mpp){
        if(it.second%2){
            cout<<"NO"<<endl;return;
        }
    }
    cout<<"YES"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}