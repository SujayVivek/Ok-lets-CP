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
    int n, x; cin>>n>>x;
    int Cx = x;
    int c = 0;
    while(x){
        if(x%2==0)break;
        else c++;
        x/=2;
    }
    int P = 1<<(c);
    int t = 0;
    int OR = 0;
    int i = 0;
    for(i = 0; i<min(P,n-1); i++){
        OR|=i;
        cout<<i<<" ";
        t++;
    }
    if((OR|i) == Cx){
        cout<<i<<" ";
    }else{
        cout<<Cx<<" ";
    }
    for(i = t; i<n-1; i++){
        cout<<0<<" ";
    }
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}