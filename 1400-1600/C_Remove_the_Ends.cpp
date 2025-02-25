#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

void Solve() {
    int n; cin>>n;
    vector<int> a(n);
    vector<int>Pos(n+1,0), Neg(n+1,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        Pos[i+1] = Pos[i]+(a[i]>0?a[i]:0);
    }
    for(int i = n-1; i>=0; i--){
        Neg[i] = Neg[i+1] + (a[i]<0?-a[i]:0);
    }
    int Ans = 0;
    for(int i = n; i>=0; i--){
        Ans = max(Ans, Pos[i]+Neg[i]);
    }
    cout<<Ans<<"\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;   
}