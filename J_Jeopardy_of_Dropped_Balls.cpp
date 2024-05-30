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
    int n, m, k;
    cin>>n>>m>>k;
    int arr[n][m];
    int dp[n][m];
    loop(i,0,n){
        loop(j,0,m){
            cin>>arr[i][j];
            dp[i][j]=-1;
        }
    }
    while(k--){
        int c;cin>>c;
        int j = c-1;int i =0;
        while(i<n ){
            if(dp[i][j]!=-1){
                i= dp[i][j]/m;
                j= dp[i][j]%m;
            }
            if(arr[i][j]==1){
                //go right 
                arr[i][j]=2;
                dp[i][j] = m*(i+1) + (j+1);
                j++;

            } 
            else if(arr[i][j]==3){
                //go left 
                arr[i][j]=2;
                dp[i][j] = m*(i+1)+j+1; 
                j--;
            } 
            else{
                //go down
                
                // dp[i][j] = m*(i+1)+j+1; 
                // i++;
                int copyi = i;
                while(arr[copyi][j]==2 && copyi<n){
                    copyi++;
                }
                // i++;

                if(i!=n-1)
                loop(q,i,copyi-1){
                  dp[q][j]=  m*(copyi)+j+1;
                }
                
                i=copyi;
            }
        }
        cout<<j+1<<" ";
    }
    cout<<endl;

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
