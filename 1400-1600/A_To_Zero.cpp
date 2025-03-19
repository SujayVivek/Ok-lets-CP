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
    int n, k; cin>>n>>k; int cnt = 0;
    if(n%2==1){
        if(k%2==1){
            cnt++; cnt+= (n-k + (k-2))/(k-1);
        }else{
            cnt++; cnt+= (n-(k-1) + (k-1))/k;
        }
    }else{
        if(k%2==1){
            cnt++; cnt+= (n-(k-1) + (k-2))/(k-1);
        }else{
            cnt++; cnt+= (n+k-1)/k;
        }
    }cout<<cnt<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}