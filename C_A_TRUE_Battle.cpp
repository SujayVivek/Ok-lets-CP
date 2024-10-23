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
     int n;cin>>n;
     string s; cin>>s;
    //  bool ans = false;
    if(s[n-1] == '1' || s[0]=='1'){
        cout<<"YES"<<endl;return;
    }
    loop(i,1,n){
        if(s[i]==s[i-1] && s[i]=='1'){
            cout<<"YES"<<endl;return;
        }
    }
    cout<<"NO"<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}