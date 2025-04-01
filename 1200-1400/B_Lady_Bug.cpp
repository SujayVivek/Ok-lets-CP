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
    string a, b; cin>>a>>b; int a1e = 0, a1o = 0, b0e = 0, b0o = 0;
    for(int i = 0; i<n; i++){
        if(i%2==0){
            if(a[i]=='1') a1e++;
            if(b[i]=='0') b0e++;
        }else{
            if(a[i]=='1') a1o++;
            if(b[i] == '0')b0o++;
        }
    }
    if(a1e<=b0o && a1o<=b0e){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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