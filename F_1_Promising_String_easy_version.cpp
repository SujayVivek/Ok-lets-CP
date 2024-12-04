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
    string s; cin>>s;
    vi S(n+1,0);
    //basically in any substring #minus - #plus %3 == 0 with #minus>#plus. As we can group 2 consecutive minus and 1 separate/consective minus. (used dirichlet principle)
    int bal = n; // so that x-a can be negative but index should not be neg
    int ans = 0;
    S[0] = bal;
    for(int i = 1; i<=n; i++){
        if(s[i]=='-') bal--;
        else bal++;
         
        S[i] = bal;
        for(int j = 0; j<i; j++){
            if(S[j]>=S[i] && (S[j]-S[i])%3==0){
                ans++;
        }
    }   
            }
    cout<<ans<<endl;return;
}
int32_t main() {
    int tt_ = 1;
  cin >>tt_;
    while (tt_--) {
        Solve();
    }
   return 0;
}