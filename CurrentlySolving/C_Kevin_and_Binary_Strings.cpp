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
    string s; cin>>s;
    int i = 0;
    while(i<s.length()){
        if(s[i]=='0'){
            break;
        }
        i++;
    }
    if(i==s.length()){
        cout<<1<<" "<<s.length()<<" "<<s.length()<<" "<<s.length()<<endl;
        return;
    }
    int cnt= i-1; int j = 0;
    for (j =i ; j <s.length() && cnt >= 0 ; j++ , cnt--) {
        if (s[j] == '1') break;
    }
    cnt++;
    cout<<1<<" "<<s.length()<<" "<<cnt+1<<" "<<cnt+s.length()-i<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}