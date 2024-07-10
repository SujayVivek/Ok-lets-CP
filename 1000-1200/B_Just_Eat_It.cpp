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
    vll v(n,0);ll ctr=0,ctr1=0;ll sum = 0;ll sumpos=0,sumneg=0; vi ans;
    loop(i,0,n){
        cin>>v[i];
        sum+=v[i];
        if(v[i]<0){
            sumneg+=v[i];
            if(sumpos!=0)
            ans.push_back(sumpos);
            sumpos=0;
        }else if(v[i]>0){
            sumpos+=v[i];
            if(sumneg!=0)
            ans.push_back(sumneg);
            sumneg=0;
        }
    }
    if(sumpos!=0)ans.push_back(sumpos);
    else if(sumneg!=0)ans.push_back(sumneg);
    if(v[0]<0 || v[n-1]<0){
        cout<<"NO"<<endl;return;
    }
    // for(auto it:ans){
    //     cout<<it<<"hi"<<endl;
    // }
    loop(i,0,ans.size()){
        if(ans[i]<0){
            if(i>0 && i<ans.size()-1 && (abs(ans[i])>=ans[i-1] || abs(ans[i])>=ans[i+1])){
                cout<<"NO"<<endl;return;
            }
        }
    }
    cout<<"YES"<<endl;return;

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