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
    map<int, vector<int>>mpI, mpN;
    vi a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpN[a[i]>>2].push_back(a[i]);
        mpI[a[i]>>2].push_back(i);
    }
    for(auto it: mpN){
        vi v = it.second;
        vi i = mpI[it.first];
        sort(v.begin(), v.end());
        for(int j = 0; j<v.size(); j++){
            a[i[j]] = v[j];
        }
    }
    for(auto v: a) cout<<v<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}