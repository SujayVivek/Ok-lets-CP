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
    int N; cin>>N;
    int S = 0;
    for(int i = 1; i<=N; i++){
        S+= i*(2*i-1);
    }
    cout<<S<<" "<<2*N<<endl;
    for(int i = N-1; i>=0; i--){
        for(int j = 1; j<=2; j++){
            cout<<j<<" "<<i+1<<" ";
            for(int k = 1; k<=N; k++){
                cout<<k<<" ";
            }cout<<endl;
        }
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