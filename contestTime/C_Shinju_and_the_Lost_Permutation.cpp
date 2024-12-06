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
     vi c(n,0);
     int cnt = 0, idx = -1;
     for(int i = 0; i<n; i++){
        cin>>c[i];
        if(c[i]==1){
            cnt++;
            idx = i;
        }
     }
     if(cnt>1 || idx==-1){
        cout<<"NO"<<endl;return;
     }
    vi subs;
    for(int i = idx; i<n; i++){
        subs.push_back(c[i]);
    }
    for(int i = 0; i<idx; i++){
        subs.push_back(c[i]);
    }
    for(int i = 0; i<n-1; i++){
        if(subs[i+1]-subs[i]>1){
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