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
    vi a(n, 0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int i = 0, j = n-1;
    while(a[i]==-1) i++;
    while(a[j]==-1) j--;
    for(int k = i; k<=j; k++){
        
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}