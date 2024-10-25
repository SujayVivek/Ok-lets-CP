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

bool prioritize(const vll &a, const vll &b) {
    int x= a[0], y = a[1], p = b[0], q = b[1];
    if(max(x,y)==max(p,q)){
        return min(x,y)<min(p,q);
    }else{
        return max(x,y)<max(p,q);
    }
}

void Solve() {
    ll n;
    cin >> n;
    vvll a(n, vll(2, 0)); 
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    
    sort(a.begin(), a.end(), prioritize);

    
    for (auto &p : a) {
        cout << p[0] << " " << p[1] <<" ";
    }cout<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}