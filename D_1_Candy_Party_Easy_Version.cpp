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
    vi a(n,0); int s = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i]; s+= a[i];
    }
    int avg = s/n;
    if(s%n!=0){cout<<"NO"<<endl;return;}
    vvi v;
    for(int i = 0; i<n; i++){
        if(a[i]>avg) v.push_back({a[i]-avg, 1});
        else if(a[i]<avg) v.push_back({avg-a[i], -1});
    }
    sort(v.begin(), v.end());
    int N = v.size();
    multiset<int>ms;
    for(int i = N-1; i>=0; i--){
        if(v[i][1]==1) {ms.insert(v[i][0]); continue;}
        if(__builtin_popcount(v[i][0])>1){
            cout<<"NO"<<endl; return;
        }
        auto it = ms.lower_bound(v[i][0]);
        if(it==ms.end()){
            cout<<"NO"<<endl;return;
        }
        ms.erase(it);
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