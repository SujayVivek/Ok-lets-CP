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
    reverse(s.begin(), s.end()); int Ans = 0;
    for(int i = 0; i<n-1; i++){
        if(s[i]=='1' && s[i+1]=='0'){
            Ans+= n-(i+1);
        }
        if(s[i]=='0' && s[i+1]=='1'){
            Ans+= n-(i+1);
        }
    }
    cout<<Ans+n<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}