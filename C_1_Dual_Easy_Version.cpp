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

void add_mx(int mx, vi &v, int mxInd){
    int n = v.size();
    vvi ans;
    int k = 0;
    loop(i,0,n-1){
        if(v[i]> v[i+1]){
            v[i]+= v[mxInd];  k++;
            ans.push_back({i,mxInd});
            i--;
        }
    }
    cout<<k<<endl;
    for(auto it: ans){
        cout<< it[0] << " "<< it[1]<<endl;
    }
}
void Solve() {
    // Your code for each test case goes here
    int n;cin>>n;vi v(n,0); int mx = 0, mn = INT_MAX, mxInd = 0, mnInd = 0;loop(i,0,n){ 
        cin>>v[i]; 
        if(v[i]>mx){mx = max(mx, v[i]); mxInd = i;}
        if(v[i]<mn){n = min(mn, v[i]); mnInd = i;}
        }
    if(mx>0 && mn< 0){
        if(mx > abs(mn)){
            //go on adding mx to elements
            add_mx(mx, v, mxInd);
        }
        else{
            //go on adding mn to elements
            add_mx(mn, v, mnInd);
        }
    }else{
        if(mx>=0 && mn>=0){
            //go on adding mx
            add_mx(mx, v, mxInd);
            
        }else{
            //go on adding mn
            add_mx(mn, v, mnInd);
        }
    }
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
