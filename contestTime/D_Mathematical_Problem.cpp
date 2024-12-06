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
    if(n==1 || n==2){
        cout<<stoi(s)<<endl;return;
    }
    if(n==3){
        if(s[0]=='0' || s[2]=='0'){
            cout<<0<<endl;return;
        }else{
            int A = stoi(s.substr(0,2));
            int B = stoi(s.substr(1,2));
            int ANS = 1e9;
            ANS = min(ANS, A + (s[2]-'0'));
            ANS = min(ANS, B + (s[0]-'0'));
            ANS = min(ANS, A * (s[2]-'0'));
            ANS = min(ANS, B * (s[0]-'0'));
            cout<<ANS<<endl;return;
        }
    }
    bool is_zero = false;
    int sum = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='0'){
            is_zero = true;
            break;
        }
        if(s[i]!='1')sum+=(s[i]-'0');
    }
    if(is_zero){
        cout<<0<<endl;return;
    }
    int ans = 1e9;
    for(int i = 0; i<n-1; i++){
        string sub = s.substr(i,2);
        int SUB = stoi(sub);
        int res = (s[i]=='1'?0:(s[i]-'0')) + (s[i+1]=='1'?0:(s[i+1]-'0'));
        ans = min(ans, sum+SUB-res);
    }
    cout<<ans<<endl;
    
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}