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
    vi ans; int j = -1;
    for(int i = 0; i<n-1; i++){
        if(s[i]==s[i+1])continue;
        int x = i-j;
        int c = ans.size();
        for(int j = 0; j<2*x; j++) ans.push_back(c + i + 1);
        j = i;
    }
    if(j==-1){
        cout<<-1<<endl;return;
    }
    int x = n-j-1;
    for(int j = 0; j<2*x; j++) ans.push_back(n + ans.size() - x);
    cout<<ans.size()<<endl;
    for(auto x: ans)cout<<x<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}