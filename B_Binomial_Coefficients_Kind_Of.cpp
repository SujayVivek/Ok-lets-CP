#include <bits/stdc++.h>

using namespace std;

//   _______ _     _                     _        _        __             _   _            _                            
//  |__   __| |   (_)                   | |      (_)      / _|           | | | |          (_)                           
//     | |  | |__  _ ___    ___ ___   __| | ___   _ ___  | |_ ___  _ __  | |_| |__   ___   _ _ __  ___  __ _ _ __   ___ 
//     | |  | '_ \| / __|  / __/ _ \ / _` |/ _ \ | / __| |  _/ _ \| '__| | __| '_ \ / _ \ | | '_ \/ __|/ _` | '_ \ / _ \
//     | |  | | | | \__ \ | |_| (_) | |_| |  __/ | \__ \ | || (_) | |    | |_| | | |  __/ | | | | \__ \ |_| | | | |  __/
//     |_|  |_| |_|_|___/  \___\___/ \__,_|\___| |_|___/ |_| \___/|_|     \__|_| |_|\___| |_|_| |_|___/\__,_|_| |_|\___|

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_k::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

const int MAX_N = 1e5 + 1; 


int solve(int k, int exp, int mod) 
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1) 
        {
            result = (1LL * result * k) % mod;
        }
        
        k = (1LL * k * k) % mod; 
        exp /= 2;
    }
    
    return result;
}

int32_t main() 
{
    int t;
    cin >> t;

    vector<int> n(t), k(t);

    for (int i = 0; i < t; ++i) 
    {
    cin >> n[i];
    }

    for (int i = 0; i < t; ++i) 
    {
        cin >> k[i];
    }

    for( int i = 0 ; i < t ; i++)
    {
        cout <<solve(2 , k[i] , MOD) <<endl;
    }

    return 0;
}