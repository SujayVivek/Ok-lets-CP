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
        int n,m; cin>>n>>m;
        vector<int> a(n);for(int &x:a) {cin>>x;}
        vector<int> b(m);for(int &x:b) {cin>>x;}
        int Kevin=a[0];
        sort(a.begin(), a.end());
        vector<int> c;
        for(int x:b)
        {
            if(x<=Kevin) {c.push_back(1);continue;}
            c.push_back(a.end()-lower_bound(a.begin(), a.end(),x)+1);
        }
        sort(c.begin(), c.end());
        for(int k=1;k<=m;++k)
        {
            int s=0;
            for(int j=k-1;j<m;j+=k)
            {
                s+=c[j];
            }
            cout<<s<<' ';
        }
        cout<<'\n';
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}