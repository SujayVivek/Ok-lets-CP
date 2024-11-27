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
    if(n%2==0){
        for(int i = 1; i<=n/2; i++){
            cout<<i<<" "<<i<<" ";
        }cout<<endl;return;
    }else{
        if(n<27){
            cout<<-1<<endl; return;
        }else{
           vector<int> v(n+2,0);
           v[1] = 1, v[10] = 1, v[26]  = 1, v[27] = 2, v[23] = 2, v[24] = 3, v[25] = 3;
           int l = 4;
            for(int i = 2; i<=n; i++){
                if(!v[i]){
                v[i] = l;
                i++;
                v[i] = l;
                l++;
                }
            }
            for(int i = 1; i<=n; i++){
                cout<<v[i]<<" ";
            }cout<<endl;return;
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