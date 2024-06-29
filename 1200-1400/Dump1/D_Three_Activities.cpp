#include <bits/stdc++.h>

using namespace std;

//   _______ _     _                     _        _        __             _   _            _                            
//  |__   __| |   (_)                   | |      (_)      / _|           | | | |          (_)                           
//     | |  | |__  _ ___    ___ ___   __| | ___   _ ___  | |_ ___  _ __  | |_| |__   ___   _ _ __  ___  __ _ _ __   ___ 
//     | |  | '_ \| / __|  / __/ _ \ / _` |/ _ \ | / __| |  _/ _ \| '__| | __| '_ \ / _ \ | | '_ \/ __|/ _` | '_ \ / _ \
//     | |  | | | | \__ \ | |_| (_) | |_| |  __/ | \__ \ | || (_) | |    | |_| | | |  __/ | | | | \__ \ |_| | | | |  __/
//     |_|  |_| |_|_|___/  \___\___/ \__,_|\___| |_|___/ |_| \___/|_|     \__|_| |_|\___| |_|_| |_|___/\__,_|_| |_|\___|

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define loopm(ii, i, n, p) for (ll ii = i; ii < n; ii+p)
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;

typedef vector<long long> vll;
typedef vector<vll> vvll;

void Solve() {
    // Your code for each test case goes here
    int n;cin>>n; ll res = 0;
    vector < ll > a(n),b(n),c(n);
        vector < pair < ll, ll > > va,vb,vc;
        pair < ll, ll > bkp,bkp2;
        for(ll i = 0 ; i < n ; i++) {
            cin>>a[i];
            va.pb(mp(a[i],i));
        }
        for(ll i = 0 ; i < n ; i++) {
            cin>>b[i];
            vb.pb(mp(b[i],i));
        }
        for(ll i = 0 ; i < n ; i++) {
            cin>>c[i];
            vc.pb(mp(c[i],i));
        }
        sort(va.begin(),va.end(),greater <> ());
        sort(vb.begin(),vb.end(),greater <> ());
        sort(vc.begin(),vc.end(),greater <> ());
 
        for(ll i = 0 ; i < 3 ; i++) {
            for(ll j = 0 ; j < 3 ; j++) {
                for(ll k = 0 ; k < 3 ; k++) {
                    if(va[i].second!=vb[j].second and va[i].second!=vc[k].second and vb[j].second!=vc[k].second) {
                        res = max(res, (va[k].first+ vb[k].first + vc[k].first));
                    }
                }
            }
        }
        cout<<res<<endl;
    
      
}

int32_t main() {
    auto begin = chrono::high_resolution_clock::now(); // Initialize the begin time measurement

    fastio();
    // #ifndef ONLINE_JUDGE
    //     freopen("error.txt", "w", stderr);
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }

    // auto end = chrono::high_resolution_clock::now();
    // auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
