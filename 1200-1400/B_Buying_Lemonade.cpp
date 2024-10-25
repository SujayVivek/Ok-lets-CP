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
    ll n, k;cin>>n>>k;
    vll a(n,0);
    for(auto &x: a)cin>>x;
    sort(all(a));
    ll s = 0;
    ll mx = 0;
    ll pres = 0;
    loop(i,0,n){
        ll r = (a[i]-mx)*(n-i);
        s+= r;
        mx = max(mx, a[i]);
        if(s==k) break;
        if(s>k){
            s-= r;
            // pres--;
            break;
        }
        pres++;
    }
    s+= (k-s);
    cout<<s+pres<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}