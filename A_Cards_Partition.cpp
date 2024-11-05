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
#define int long long;

void Solve() {
    ll n,k; cin>>n>>k;
    ll s=0, m=0,x;
    for(ll i=1; i<=n; i++){
        cin>>x;
        s+=x;
        m=max(m,x);
    }
    for(ll i=n; i; i--){
        if((s+k)/i>=m && (s-1)/i!=(s+k)/i){
            cout<<i<<"\n";
            break;
        }
    }
}

int32_t main() {
    ll tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}