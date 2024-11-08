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
    int k = 0;
    vi ans;
    if(n%2==1){
        ans.pb(2); ans.pb(1);
        k&=2;
        k|=1;
        for(int i = 3; i<=n; i++){
            if(i%2==1)k&=i;
            else k|=i;
            ans.pb(i);
        }
    }
    else{
        int b = 32-__builtin_clz(n);
        int p = pow(2, b-1)-1;
        k&=2; k|=1;
        ans.pb(2); ans.pb(1);
        for(int i = 3; i<p; i++){
            if(i%2==0)k|=i;
            else k&=i;
            ans.pb(i);
        }
        for(int i = p; i<n; i++){
            if(i%2==1) k&=(i+1);
            else k|=(i+1);
            ans.pb(i+1);
        }
        ans.pb(p);
        k|=p;
        // k = pow(2,b)-1;
    }
    cout<<k<<endl;
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}