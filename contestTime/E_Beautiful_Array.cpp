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
    vi a(n,0);
    map<int,int> mpp;
    for(int i = 0;i<n; i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    vi v;
    for(auto it: mpp){
        if(it.second%2==1){
            v.push_back(it.first);
        }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    map<int, vi> mpv;
    for(int i = 0; i<v.size(); i++){
        mpv[v[i]%k].push_back(v[i]);
    }
    int count = 0;
    for(auto it: mpv){
        if(it.second.size()%2==1 ){
            count++;
        }
        auto vec = it.second;
        for(int i = 0; i<vec.size(); i+=2){
            if(i+1<vec.size())
            ans += (abs(v[i+1]-v[i]))/k;
        }
        if(count>1){
            cout<<-1<<endl;return;
        }
    }
    cout<<ans<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}