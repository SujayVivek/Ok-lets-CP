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
    vi a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    string s; cin>>s;
    int A = 0, B = n-1; 
    for(int i = 0; i<s.length()-1; i++){
        if(s[i] == 'L') A++;
        else B--;
        if(A==B) break;
    }
    int Ans = a[B]%m;
    vector<int> res;
    for(int i = n-2; i>=0; i--){
        res.push_back(Ans);
        if(s[i] == 'L') {A--;Ans = (Ans*a[A])%m;}
        else {B++; Ans = (Ans*a[B])%m;}
    }
    res.push_back(Ans);
    reverse(res.begin(), res.end());
    for(auto &x: res)cout<<x<<" ";
    cout<<endl; 
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}