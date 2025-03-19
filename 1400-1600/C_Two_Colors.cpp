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
    int n, m; cin>>n>>m;
    vi a(m,0);
   for( int i = 0; i<m; i++){
        cin>>a[i];
        a[i] = min(a[i], n-1);
   }
   sort(a.begin(), a.end());
   int ans = 0; vi suf(m+1);
   for(int i = m-1; i>=0; i--)suf[i] = suf[i+1]+ a[i];
   for(int i = 0, j = m-1; i<m; i++){
    j = max(i, j);
    while(j>i && a[i]+a[j]>=n) j--;
    ans+= (a[i]-n+1)*(m-1-j) + suf[j+1];
   }   cout<<2*ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}