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
    map<int,int>mpp;
    for(int i = 0; i<7; i++){
        int x; cin>>x;
        mpp[x]++;
    } vector<int> v;
    for(auto it: mpp){
        v.push_back(it.second);
    }
    sort(v.begin(), v.end(), greater<int>());
    if(v.size()<2){cout<<"No"<<endl;return;}
    if(v[0]>=3 && v[1]>=2){
        cout<<"Yes"<<endl;return;
    }else{
        cout<<"No"<<endl;return;
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}