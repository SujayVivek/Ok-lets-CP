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
    if(__builtin_popcount(n) == 1 || __builtin_popcount(n) == (64-__builtin_clzll(n))){
        cout<<-1<<endl;
    }else{
        int Ans = 0; bool ok1 = false, ok2 = false;
        for(int i = 0; i<32; i++){
            if(n&(1<<i)){
                if(!ok1)Ans+= 1<<i; ok1 = true;
            }else{
                if(!ok2)Ans+= 1<<i; ok2 = true;
            }
            if(ok1 && ok2) break;
        }
        cout<<Ans<<endl;
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