#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int solve() {
    int small, big; cin>>small>>big; int sNum = 0, bNum = 0;
    if(small>big){return 0;}
    while(big){
        if(small%2==1) sNum++;
        if(big%2==1) bNum++;
        small/=2, big/=2;
        if(sNum<bNum) return 0;
    }
    if(sNum<bNum) return 0;
    return 1;
}
void Solve(){
    if(solve()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}