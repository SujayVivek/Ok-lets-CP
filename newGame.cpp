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
    int n, k;cin>>n>>k;
    map<ll,ll>mpp;
    for(int i = 0 ; i<n ; i++){
        ll x; cin>>x;
        mpp[x]++;
    }
    vvll a;
    int p = mpp.size();
    ll mx = 0;int c =0;vi hash(p, 0);
    for(auto it: mpp){
        a.pb({it.ff, it.ss});
        mx = max(mx, it.ss);
        c++;
        if(c>0){
            if(a[c][0]-a[c-1][0] == 1){
                hash[c] = 
            }
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