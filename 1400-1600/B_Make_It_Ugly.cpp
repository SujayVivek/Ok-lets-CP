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
    vi v(n,0);
    for(auto &x: v)cin>>x;
    if(v[0]!=v[n-1]){
        cout<<0<<endl;return;
    }
    int a = 0, ans = 1e9;
    for(int i = 0; i<n; i++){
        if(v[i]==v[0]) a++;
        else{
            ans= min(ans, a);
            a = 0;
        }
    }
    ans = min(ans, a);
    if(ans==n){
        cout<<-1<<endl;return;
    }else{
        cout<<ans<<endl;return;
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