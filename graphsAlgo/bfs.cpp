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

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int n, m;
vvi arr;
vector<vector<pair<int,int>>> par;
bool check(int x, int y){
    if(x>=0 && y>=0 && y<m && x<n && arr[x][y]!='#')return 1;
    return 0;
}
void bfs(pair<int,int> st){
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vi(m, 1e9));
    par.assign(n, vector<pair<int,int>>(m, {0,0}));

    dist[st.ff][st.ss] =0;
    q.push(st);
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        for(int k = 0 ; k<4; k++){
            if(check(pos.ff + dx[k], pos.ss + dy[k]) && dist[pos.ff + dx[k]][pos.ss + dy[k]]>dist[pos.ff][pos.ss]+1){
                dist[pos.ff + dx[k]][pos.ss + dy[k]]=dist[pos.ff][pos.ss]+1;
                par[pos.ff + dx[k]][pos.ss + dy[k]] = {pos.ff, pos.ss};
                q.push({pos.ff + dx[k], pos.ss + dy[k]});
            }
        }
    }

}
void ppath(pair<int,int> en){
    if(en == MP(-1,-1)) return;
    ppath(par[en.ff][en.ss]);
    cout<<en.ff<<" "<<en.ss<<endl;
}
void Solve() {
    // Your code for each test case goes here
    cin>>n>>m;
    arr.resize(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m;j++){
            cin>>arr[i][j];
        }
    }
    pair<int, int> st, en;
    cin>>st.ff>>st.ss;
    cin>>en.ff>>en.ss;
    bfs(st);
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