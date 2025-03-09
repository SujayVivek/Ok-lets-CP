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
    vvi a(n, vi(2, 0));
    for(int i = 0; i<n; i++){
        cin>>a[i][1];
    }
    for(int i = 0; i<n; i++){
        cin>>a[i][0];
    }
    sort(a.begin(), a.end());int Time = 0; int i = 0;
    for( i = 0; i<n-1; i++){
        Time+= a[i][1];
        a[i+1][1]+= a[i][0];
    }
    Time+= a[i][1];
    cout<<Time<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}