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
    string s1, s2; cin>>s1>>s2;
    int num1 = 0, num0 = 0;
    for(int i = 0; i<n; i++){
        if(s1[i]=='1') num1++;
        else num0++;
    }
    if(n==1){
        cout<<"YES"<<endl;return;
    }
    for(int i = 0; i<n-1; i++){
        if(num0==0 || num1==0){
            cout<<"NO"<<endl; return;
        }
        if(s2[i]=='1'){
            num0--;
        }else{
            num1--;
        }
    }cout<<"YES"<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}