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

long long mod = 998244353;

// long long mod = 998244353;

// Function to calculate (base^exp) % mod
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll modInverse(ll x, ll mod) {
    return power(x, mod - 2, mod);
}

void Solve() {
    ll n;cin>>n;
    ll p = n/3;
    map<ll,int>mpp;
    ll c = 1;
    ll d = 1;
    loop(i,0,n){
        ll x; cin>>x;
        if(i%3==0 && i!=0){
            if(mpp.size()==1){
                c=(3*c)%mod;
            }else if(mpp.size()==2){
                auto it = mpp.begin();
                if(it->ss == 2){
                    d=(2*d)%mod;
                }
            }
            mpp.clear();
        }
        mpp[x]++;
    }
    if(mpp.size()==1){
                c=(3*c)%mod;
    }else if(mpp.size()==2){
                auto it = mpp.begin();
                if(it->ss == 2){
                    d=(2*d)%mod;
                }
    }
    ll factp = 1, factp_2 = 1;
    for (int i = 1; i <= p; i++) {
        if (i <= p / 2) factp_2 = (factp_2 * i) % mod;
        factp = (factp * i) % mod;
    }
    ll inv_factp_2 = modInverse(factp_2, mod);
    ll ans = 1;
    if (p % 2 == 1) {
        ll mid_term = (p / 2 + 1);
        ll inv_mid_term = modInverse(mid_term, mod);
        ans = (factp * inv_factp_2 % mod * inv_factp_2 % mod * inv_mid_term % mod) % mod;
    } else {
        ans = (factp * inv_factp_2 % mod * inv_factp_2 % mod) % mod;
    }
    cout << (ans * c % mod * d % mod) % mod << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}