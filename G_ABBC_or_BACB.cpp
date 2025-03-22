#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int funct(string s, int n){
    int i = 0, cnt = 0;
    for(i = 0; i<n-2; i++){
        if(s[i] == 'A' && s[i+1] == 'B'){
            if(s[i+2] == 'A'){
                s[i+1] = 'C'; s[i+2] = 'B';
                cnt++;
            }else{
                s[i] = 'B', s[i+1] = 'C';
                cnt++;
            }
        }else if(s[i]=='B' && s[i+1]=='A'){
            s[i] = 'C', s[i+1] = 'B';
            cnt++;
        }
    }
    if(s[i]=='A' && s[i+1] == 'B'){
        s[i] = 'B', s[i+1] = 'C';
                cnt++;
    } else if(s[i] == 'B' && s[i+1] == 'A'){
        s[i] = 'C', s[i+1] = 'B';
            cnt++;
    }
    return cnt;
}
void Solve() {
    string s; cin>>s; int n = s.length(); int cnt = 0;
    string p = s; reverse(s.begin(), s.end());
    cout<<max(funct(p, n), funct(s, n))<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}