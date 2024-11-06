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
#define int long long
void Solve() {
    int n;cin>>n;
    vi a(n,0);
    // vi suff(n,0), pref(n,0);
    for(auto &x : a) cin >> x;
    ll sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if(sum <= 0) {cout<<"NO"<<endl;return;}
    }
    sum = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        sum += a[i];
        if(sum <= 0) {cout<<"NO"<<endl;return;}
    }
    cout<<"YES"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}