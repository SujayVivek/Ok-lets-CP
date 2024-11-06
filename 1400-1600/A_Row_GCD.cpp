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

void Solve(){
    ll n, m; cin>>n>>m;
        ll x_0; cin>>x_0;
        ll gcd_1 = 0;
        ll x;
        for(int i=1;i<n;i++) {
            cin>>x;
            gcd_1 = __gcd(abs(x-x_0),gcd_1);
        }
        for(int i=0;i<m;i++){
            cin>>x;
            cout<<__gcd(x_0+x,gcd_1)<<" ";
        }
        return;
}
int main(){
    int tt=1;
    // cin>>tt;
    while(tt--){
        Solve();
    }
}