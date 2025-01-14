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
     vi a(n,0), b(n,0);
     for(int i = 0; i<n; i++){
        cin>>a[i];
     }
     int cnt = 0, Min = 0, Max = 1e9;
     for(int i = 0; i<n; i++){
        cin>>b[i];
        if(a[i]>=b[i]){
            Max = min(Max, a[i]-b[i]);
        }else{
            cnt++;
            Min = max(Min, b[i]-a[i]);
        }
     }
     if(cnt<=1 && Min<=Max){
        cout<<"YES"<<endl;
     }else{
        cout<<"NO"<<endl;
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