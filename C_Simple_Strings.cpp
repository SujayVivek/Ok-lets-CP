#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define endl "\n"
#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

void Solve() {
    string s;cin>>s;
    s = '$' + s + '$';
    int n = s.length();
    for(int i = 2; i<=n-1; i++){
        if(s[i]==s[i-1] && s[i]==s[i+1]){
            s[i] = (s[i]=='z') ? 'a': (char)(s[i]+1);
        }
    }
    for(int i = 1; i<=n; i++){
        if(s[i]==s[i+1] || s[i]==s[i-1]){
            char c = s[i];
            while(c==s[i+1] || c==s[i-1]){
                c = (c == 'z') ? 'a' : (char)(c + 1);
            }
            s[i] = c;
        }
    }
    cout<<s.substr(1,n-2)<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}