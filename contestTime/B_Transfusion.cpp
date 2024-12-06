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
    vi a(n,0);
    int sumE = 0, sumO = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(i%2==0){
            sumE+=a[i];
        }else{
            sumO+=a[i];
        }
    }
    if(n%2==0){
        int q = n/2;
        if(sumE%q==0 && sumO%q==0 && sumE == sumO){
            cout<<"YES"<<endl;return;
        }else{
            cout<<"NO"<<endl;return;
        }
    }else{
        int q = n/2;
        if(sumE%(q+1)==0 && sumO%q==0 && (sumE/(q+1))==(sumO/q)){
            cout<<"YES"<<endl;return;
        }else{
            cout<<"NO"<<endl;return;
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