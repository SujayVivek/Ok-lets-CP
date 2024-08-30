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
#define MP make_pair
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
    ll n;cin>>n;
    vll a(n,0);
    vll ans;vll prfXor(n,0);
    cin>>a[0]; prfXor[0] = a[0];
    loop(i,1,n){
        cin>>a[i];
        prfXor[i] = a[i]^prfXor[i-1];
    }
    
    string s;cin>>s;ll xor0 = 0, xor1 = 0;
    loop(i,0,s.length()){
        if(s[i]=='0'){
            xor0^= a[i];
        }else{
            xor1^= a[i];
        }
    }
    ll q;cin>>q;
    while(q--){
        int l;cin>>l;
        if(l==1){
            ll p, q;cin>>p>>q;p--;q--;
            ll compute = (p!=0)?(prfXor[q]^prfXor[p-1]):prfXor[q];
            xor1^=compute;
            xor0^=compute;
        }else{
            int p;cin>>p;
            if(p==1){
                cout<<xor1<<" ";
            }else{
                cout<<xor0<<" ";
            }
        }
        
    }cout<<endl;
return;
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