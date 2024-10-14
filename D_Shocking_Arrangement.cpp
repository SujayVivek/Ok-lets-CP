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
    vll a, b;
    ll mx = 0, mi = 1e9;
    for(int i = 0; i<n; i++){
        ll x; cin>>x;
        if(x>=0) a.pb(x);
        else b.pb(x);
        
        mx = max(mx, x);
        mi = min(mi, x);
    }
    ll dif = mx-mi;
    sort(all(a));
    sort(all(b));
    ll s = 0;
    ll i = 0, j = 0;
    vll ans;
    while(i<a.size() && j<b.size()){
        s+=a[i];
        if(s>=dif){
            s-=a[i];
            s+=b[j];
            ans.pb(b[j]);
            j++;
        }else{
            ans.pb(a[i]);
            i++;
        }
    }
    while(i<a.size()){
        s+=a[i];
        if(s>=dif){
            cout<<"No"<<endl;return;
        }
        ans.pb(a[i]);
        i++;
    }
    while(j<b.size()){
        ans.pb(b[j]);
        j++;
    }
    cout<<"Yes"<<endl;
    for(auto v: ans){
        cout<<v<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}