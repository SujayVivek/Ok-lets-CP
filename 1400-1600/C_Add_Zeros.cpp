#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define int long long
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
    vi a(n,0);
    map<ll, vll>mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]+i].pb(a[i]+i+i);
    }
    set<ll> vis;
    function<void(ll)> dfs = [&](ll u) -> void {
        if(vis.count(u)) return;
        vis.insert(u);
        for(auto nn: mpp[u]) dfs(nn);
    };
    dfs(n);
    cout<<*vis.rbegin()<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}