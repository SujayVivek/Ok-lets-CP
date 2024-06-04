#include <bits/stdc++.h>

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define INF 1e18
#define endl "\n"
#define pb push_back
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
    cin >> n;
    vi v(n, 0);
    // cin >> v[0];
    int ctr = 0;
    int mx = 0;

    loop(i, 0, n) {
        cin >> v[i];
    }
    loop(i,1,n){
        int gc = __gcd(v[i], v[i-1]);
        cout<<"v[i]= "<<v[i]<<" ";
        cout<<"v[i]-1= "<<v[i-1]<<endl;;
        cout << "CTR= " << ctr << " GCD= " << gc << endl;

        if (gc >= mx) {
            mx = gc;
        } else {
            v[i] = v[i-1];
            ctr++;
        }

        // Debugging output, can be commented out for production
        

        if (ctr == 2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
} 


int32_t main() {
    auto begin = chrono::high_resolution_clock::now(); // Initialize the begin time measurement

    fastio();
    // #ifndef ONLINE_JUDGE
    //     freopen("error.txt", "w", stderr);
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }

    // auto end = chrono::high_resolution_clock::now();
    // auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

    return 0;
}
