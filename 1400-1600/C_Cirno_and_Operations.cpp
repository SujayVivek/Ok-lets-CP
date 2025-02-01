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
    vi a(n,0);
    int S = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        S+= a[i];
    }
    if(n==1){
        cout<<S<<endl;return;
    }
    int N = n;
    int Ans = S;
    while(N>1){
        int PreSum = 0;
        for(int i = 0; i<N-1; i++){
            a[i] = a[i+1]-a[i];
            PreSum+= a[i];
        }
        Ans = max(Ans, PreSum);
        Ans = max(Ans, -PreSum);
        N--;
    }
    cout<<Ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}