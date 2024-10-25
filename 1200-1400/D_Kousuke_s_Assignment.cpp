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
    ll n;cin>>n;
    vll a(n,0);
    for(auto &x:a)cin>>x;
    map<ll,int> mpp;
    ll c = 0;
    ll s = 0;
    for(ll i = 0; i<n; i++){
        if(a[i]==0){
            mpp.clear();c++;s = 0; continue;
        }
        s+=a[i];
        if(s==0){
            c++; s=0;
            mpp.clear();
        }
        if(!mpp[s]){
            mpp[s]++;
        }else if(mpp[s]){
            c++; s = 0;
            mpp.clear();
        }
    }
    cout<<c<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}