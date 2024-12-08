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
    int n,k; cin>>n>>k;
    vi a(n, 0);
    for(auto &x: a) cin>>x;

    for(int i = 0 ; i < n ; i++){ 
        bool ok =true; 
        for(int j = 0 ; j < n ; j++){ 
            if(i==j)continue;
            if(abs(a[i] - a[j]) % k  == 0){ 
                ok = false; 
                break; 
            } 
        } 
        if(ok){ 
            cout<< "YES"<< endl; 
            cout << i+1 << endl; 
            return;  
        } 
    } 
    cout  << "NO"<< endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}