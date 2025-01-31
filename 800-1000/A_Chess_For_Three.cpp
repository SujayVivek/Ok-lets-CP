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
    int a, b, c; cin>>a>>b>>c;
    int S = a + b + c;
    if(S%2){
        cout<<-1<<endl;return;
    }
    if(a+b<=c){
        cout<<a+b<<endl;return;
    }
    S = a/2 + b/2 + c/2;
    a%=2, b%=2, c%=2;
    cout<<S + (a+b+c)/2<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}