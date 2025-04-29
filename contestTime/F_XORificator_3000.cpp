#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int xor_uptoN(int n){
    if(n%4==0) return n;
    else if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else return 0;
}
int calc(int n, int i, int k){
    int ans = xor_uptoN(n);
    int x = n>>i;
    if(n%(1<<i)<k) x--;
    int rem = xor_uptoN(x)<<i;
    if(x%2==0) rem^=k;
    return (ans^rem);
}
void Solve() {
    int l, r, i, k; cin>>l>>r>>i>>k;
    cout<< (calc(r, i, k)^(calc(l-1, i, k)))<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}