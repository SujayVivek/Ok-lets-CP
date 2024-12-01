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
        int n;cin>>n;
        vi a(n,0), b(n,0);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        int ed=a[n];
        int st=a[n]-b[n]+1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(st>a[i]){
                ans+=(1+ed-st+1)*(ed-st+1) /2;
                st=a[i]-b[i]+1;
                ed=a[i];
            }
            else st=min(a[i]-b[i]+1,st);
        }
        cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}