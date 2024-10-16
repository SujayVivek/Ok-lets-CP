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
    map<ll,ll>mpp;
    for(int i = 0 ; i<n ; i++){
        ll x; cin>>x;
        mpp[x]++;
    }
    vvll a;
    ll mx = 0;
    for(auto it: mpp){
        a.pb({it.ff, it.ss});
        mx = max(mx, it.ss);
    }
    if(k==1){
        cout<<mx<<endl;return;
    }
    if(n==1){
        cout<<1<<endl;return;
    }
    ll i = 0, j = 1;
    ll p = a.size();
    ll dif = 1;
    ll s = a[i][1];
    while(i<p && j<p){
        if(a[j][0]-a[i][0] == dif){
            mx = max(mx, s);
            s+= a[j][1];
            if(dif+1>k){
                s-=a[i][1];
                mx = max(mx, s);
                i++;
                dif--;
            }else{
                mx = max(mx, s);
            }
            j++;
            dif++;
        }else{
            mx = max(mx, s);
            s = a[j][1];
            i = j;
            dif = 1;
            j++;
        }
    }
    mx = max(mx, s);
    cout<<mx<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}