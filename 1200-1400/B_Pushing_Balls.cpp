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
    int n, m; cin>>n>>m;
    vector<string> vs(n);
    for(int i = 0; i<n; i++){
        cin>>vs[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(vs[i][j]=='1'){
                bool ok1 = true, ok2 = true;
                for(int a = i; a>=0; a--){
                    if(vs[a][j]=='0'){
                        ok1 = false; break;
                    }
                }
                for(int a = j; a>=0; a--){
                    if(vs[i][a]=='0'){
                        ok2 = false; break;
                    }
                }
                ok1 = ok1|ok2;
                if(!ok1){
                    cout<<"NO"<<endl;return;
                }
            }
        }
    }
    cout<<"YES"<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}