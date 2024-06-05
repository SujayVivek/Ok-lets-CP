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
    ll n,k,x;
    cin>>n>>k>>x;
    vll v(n,0);
    loop(i,0,n){
        cin>>v[i];
    }
    sort(all(v));
    ll groups = 0;
    vll differs;
    vvll gapv;

    loop(i,1,n){
        if(v[i]-v[i-1]> x){
            differs.push_back(v[i-1]);
            differs.push_back(v[i]);
            groups++;
            ll gap = v[i]- v[i-1];
            gapv.push_back({gap, groups});
        }
    }
    // loop(i,0,differs.size()){
    //     cout<<differs[i]<<" ";
    // }cout<<endl;
    if(differs.size()==0){
        cout<<1<<endl;
        return;
    }
    groups++;
    if(k==0){
        cout<<groups<<endl;
        return;
    }
    ll q = gapv.size();ll flag = 0;
    sort(all(gapv));
    for(ll i = 0;i<q; i+=1){
        ll nums = floor((gapv[i][0])/x) - (gapv[i][0]%x==0? 1:0);
        // cout<<"NUms"<<nums<<endl;
        if(k-nums<0){
            // cout<<"lol"<<i<<endl;
            groups--;
            flag = -1;
            break;
        }
        groups--;
        k-=nums;
        // cout<<k<<endl;
        if(k==0){
            break;
        }  
    }
    if(flag ==-1){
        cout<<groups+1<<endl;
        return;
    }
    cout<<groups<<endl;

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
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }

    // auto end = chrono::high_resolution_clock::now();
    // auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
