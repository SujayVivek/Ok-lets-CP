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
    int n;cin>>n;
    string s;cin>>s;int c = n;
    if(n%2==0){
        map<char,int>mpEv, mpOd;
        loop(i,0,n){
            if(i%2==0){
                mpEv[s[i]]++;
            }else{
                mpOd[s[i]]++;
            }
        }int m = 0;
        for(auto it:mpEv){
            m = max(m, it.ss);
        }
        int p = 0;
        for(auto it: mpOd){
            p = max(p, it.ss);
        }
        c -=(m+p);
        cout<<c<<endl;return;
    }else{
        vvi pref(2,vi(26)), suff(2,vi(26));
        for(int i = n-1; i>=0;i--){
            suff[i%2][s[i]-'a']++;
        }
        loop(i,0,n){
            suff[i%2][s[i]-'a']--;
            int ans = n;
            loop(k,0,2){
                int mx = 0;
                loop(j,0,26){
                    mx = max(mx, pref[k][j]+ suff[1-k][j]);
                }
                ans-=mx;
            }
            c = min(c,ans);
            pref[i%2][s[i]-'a']++;
        }
        cout<<c<<endl;return;
    }
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