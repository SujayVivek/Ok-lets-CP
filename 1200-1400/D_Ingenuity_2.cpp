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

    int n;
    string s;
    cin >> n >> s;
 
    int N = count(all(s), 'N');
    int S = count(all(s), 'S');
    int E = count(all(s), 'E');
    int W = count(all(s), 'W');
    bool ok = (N % 2 == S % 2);
    ok &= (E % 2 == W % 2);
 
    if (!ok)
    {
        cout<<"NO"<<endl;
        return;
    }
    
    map<char, vector<int>> mp;
    for (int i = 0; i < n; ++i)
        mp[s[i]].push_back(i);
    
    string ans = s; 
    vector<int>& ntmp = mp['N'], stmp = mp['S'];
 
    int j = 0;
    while (j < min(sz(ntmp), sz(stmp)))
    {
        if (j % 2)
            ans[ntmp[j]] = ans[stmp[j]] = 'R';
        else
            ans[ntmp[j]] = ans[stmp[j]] = 'H';
        ++j;
    }
 
    while (j < sz(ntmp))
    {
        if (j % 2)
            ans[ntmp[j]] = 'R';
        else
            ans[ntmp[j]] = 'H';
        ++j;
    }
 
    while (j < sz(stmp))
    {
        if (j % 2)
            ans[stmp[j]] = 'R';
        else
            ans[stmp[j]] = 'H';
        ++j;
    }
 
    vector<int>& etmp = mp['E'], wtmp = mp['W'];
    j = 0;
    while (j < min(sz(etmp), sz(wtmp)))
    {
        if (j % 2)
            ans[etmp[j]] = ans[wtmp[j]] = 'R';
        else
            ans[etmp[j]] = ans[wtmp[j]] = 'H';
        ++j;
    }
 
    while (j < sz(etmp))
    {
        if (j % 2)
            ans[etmp[j]] = 'R';
        else
            ans[etmp[j]] = 'H';
        ++j;
    }
 
    while (j < sz(wtmp))
    {
        if (j % 2)
            ans[wtmp[j]] = 'R';
        else
            ans[wtmp[j]] = 'H';
        ++j;
    }
 
    int h = count(all(ans), 'H');
    int r = count(all(ans), 'R');
 
    if (r == 0 || h == 0)
    {
        if (N % 2 && E == 0)
        {
            cout<<"NO"<<endl;
            return;
        }
        if (E % 2 && N == 0)
        {
            cout<<"NO"<<endl;
            return;
        }
 
        for (int i = 0; i < n; ++i)
            if (s[i] == 'N' || s[i] == 'S')
                ans[i] = 'H';
            else
                ans[i] = 'R';
    }
 
    cout << ans << "\n";

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
