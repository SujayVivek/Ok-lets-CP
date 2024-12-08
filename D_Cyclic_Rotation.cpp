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
    vi a(n,0), b(n,0);
    for(auto &x: a) cin>>x;
    for(auto &x: b) cin>>x;
    map<int,int> hash;
    int i = 0, j = 0;
    while(j<=n-1){
        if(a[i]==b[j] && i<n){
            i++, j++; continue;
        }else if(hash[b[j]]>0 && b[j] == b[j-1]){
            hash[b[j]]--;
            j++;
        }else if(i<n){
            hash[a[i]]++;
            i++;
        }else{
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