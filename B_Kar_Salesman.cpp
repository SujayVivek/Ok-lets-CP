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
    ll n, x;cin>>n>>x;
    vll a(n,0);
    for(auto &v: a)cin>>v;
    if(x==1) {cout<<n<<endl; return;}
    ll ans = 0;
    sort(all(a), greater<int>());
    while(a[0]!=0){
        ll p = min(n,x);
        ans+=a[p-1];
        if(a[p-1])
        for(int i = 0; i<p; i++){
            a[i] = a[i] - a[p-1];
        }
        n--;
        sort(all(a),greater<int>());
        if(a[1]==0){
            ans+= a[0];
            break;
        }
    }
    cout<<ans<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}