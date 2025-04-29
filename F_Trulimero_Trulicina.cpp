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
    int n, m, k; cin>>n>>m>>k;
    if(m%k){
        int T = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<(T%k)+1<<" ";
                T++;
            }cout<<endl;
        }
    }else{
        vi a, b;
        for(int i = 0; i<k; i++){
            a.push_back(i+1);
            if(i)b.push_back(i+1);
        }b.push_back(1);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i%2) cout<<a[j%k]<<" ";
                else cout<<b[j%k]<<" ";
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