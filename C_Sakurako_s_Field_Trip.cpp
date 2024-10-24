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

void swap(int i, int j, vi &v){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void Solve() {
    // Your code for each test case goes here
    int n;cin>>n;
    vi a(n, 0);
    for(auto &x: a)cin>>x;
    int ans = 0;
    if(n%2==0){
        int i = n/2-1; int j = n/2;
        int k = 0;
        while(i-k>0 && j+k<n-1){
            if(a[i-k]==a[j+k]){
                if(k==0 && a[i]==a[j]) ans++;
                k++;continue;
            }
            int d = 0;
            if(a[i-k] == a[i-k-1]){
                d++;
            }
            if(a[j+k] == a[j+k+1]){
                d++;
            }
            if(a[i-k+1]==a[i-k]){
                d++;
            }
            if(a[j+k-1] == a[j+k]){
                d++;
            }
            swap(i-k, j+k, a);
            int r = 0;
            if(a[i-k] == a[i-k-1]){
                r++;
            }
            if(a[j+k] == a[j+k+1]){
                r++;
            }
            if(a[i-k+1]==a[i-k]){
                r++;
            }
            if(a[j+k-1] == a[j+k]){
                r++;
            }
            if(r>=d){
                swap(i-k,j+k,a);
            }
            ans += min(r,d);
            k++;
        }
    }
    else{
        int i = n/2-1; int j = n/2+1;
        int k = 0;
        while(i-k>0 && j+k<n-1){
            // if(a[i-k]==a[j+k]){k++;continue;}
            int d = 0;
            if(a[i-k] == a[i-k-1]){
                d++;
            }
            if(a[j+k] == a[j+k+1]){
                d++;
            }
            if(a[i-k+1]==a[i-k]){
                d++;
            }
            if(a[j+k-1] == a[j+k]){
                d++;
            }
            swap(i-k, j+k, a);
            int r = 0;
            if(a[i-k] == a[i-k-1]){
                r++;
            }
            if(a[j+k] == a[j+k+1]){
                r++;
            }
            if(a[i-k+1]==a[i-k]){
                r++;
            }
            if(a[j+k-1] == a[j+k]){
                r++;
            }
            if(r>=d){
                swap(i-k,j+k,a);
            }
            ans += min(r,d);
            k++;
        }
    }
    int d = 0;
    if(a[0] == a[1]){
        d++;
    }
    if(a[n-1]==a[n-2]){
        d++;
    }
    int r = 0;
    swap(0, n-1, a);
    if(a[0] == a[1]){
        r++;
    }
    if(a[n-1]==a[n-2]){
        r++;
    }
    ans+= min(r,d);
    cout<<ans<<endl;
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