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
    vi a, b; for(int i = 0; i<n; i++){
        int x; cin>>x; a.push_back(x);
    }int S = 0;
    for(int j = 0; j<n; j++){
        int x; cin>>x; b.push_back(x);
    }priority_queue<int> pq;
    for(int i = 0; i<n; i++){
        pq.push(min(a[i], b[i]));
        S+= max(a[i], b[i]);
    }k--;
    while(k--){
        S+=pq.top(); pq.pop();
    }cout<<S+1<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}