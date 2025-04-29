#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
string p, s; 
void Solve() {
    cin>>p>>s; int i = 0, j = 0; s+='$', p+='$';
    while(i<p.length() && j<s.length()){
        int i_new = i, j_new = j;
        while(p[i_new]==p[i])i_new++;
        while(s[j_new]==s[j])j_new++;
        // cout<<i_new<<" "<<j_new<<" "<<endl;
        if(p[i]!=s[j] || (i_new - i)>(j_new - j) || 2*(i_new - i)<(j_new - j)){cout<<"NO"<<endl; return;}
        i = i_new, j = j_new;
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