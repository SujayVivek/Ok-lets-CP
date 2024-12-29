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
    int l, r, g; cin>>l>>r>>g;
    int L = l + ((l%g==0)?0:(g-l%g));
    int R = r - r%g;
    for(int i = 0; i<= (R-L)/g; i++){
        for(int j = 0; j<=i; j++){
            if(__gcd(L + j*g, R - (i-j)*g) == g){
                cout<<L + j*g<<" "<<R - (i-j)*g<<endl;return;
            }
        }
    }
    cout<<-1<<" "<<-1<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}