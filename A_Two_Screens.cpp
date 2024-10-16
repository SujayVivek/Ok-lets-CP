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
    string s, t;cin>>s>>t;
    int ans = 0;
    bool copy = false;
    int j = 0;
    loop(i,0,min(s.length(), t.length())){
        if(s[i]==t[i]){
            ans++;
            copy = true;
        }else{
            break;
        }
        j = i+1;
    }
    // cout<<ans<<"HI"<<j<<"hi";
    if(copy){
        ans++;
    }
    ans+= max((int)s.length()-j,0) + max((int)t.length()-j,0);
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