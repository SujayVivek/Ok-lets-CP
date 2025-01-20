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
    if(n%2==0){
        cout<<n/2<<" "<<n/2<<endl;
    }else{
        int L = 1;
        int a = 0, b = 0;
        while(n){
            int p = n%10;
            if(a>=b){
                a += (p / 2) * L;
                b+= (p/2 + p%2)*L;
            }else{
                a+=(p/2 + p%2)*L;
                b+= (p/2)*L;
            }
            L*=10;
            n/=10;
        }
        cout<<a<<" "<<b<<endl;
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