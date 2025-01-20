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
    vector<string> v(n);
    for(int i = 0; i<n; i++){
        string s; cin>>s;
        v[i] = s;
    }
    vi ans(n,-1);
    for(int i = n-1; i>=0; i--){
        int cnt = 0;
        for(int j = 0; j<i; j++){
            if(v[j][i]=='1'){
                cnt++;
            }
        }
        for(int j = 0; j<n; j++){
            if(ans[j]==-1){
                if(cnt==0){
                    ans[j] = i;
                    break;
                }
                cnt--;
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]+1<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}