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


vi anz;
int check(int md,int sum,int dif,int n){
    int a = md;int b = md-dif;
    b= min(10000,b);
    return (a*n-b)>=sum;
}
void bs(int lo, int hi, int n,int dif,int ctr){
    int sum = 0;int ans;int t = pow(10,ctr);
    loop(i,0,dif){
            sum+= n;
            if(i!=dif-1)sum*=t;
    }
    while(lo<=hi){
        int md = (lo+hi)/2;
        
        if(check(md,sum,dif,n)){
            ans = md;
            hi = md-1;
        }else{
            lo = md+1;
        }
    }
    if(ans*n-(ans-dif)==sum){
        anz.pb(ans);
        anz.pb(ans-dif);
    }
    return;
}
void Solve() {
    // Your code for each test case goes here
    int n;cin>>n;
    int copyn = n;
    int ctr = 0;
    while(copyn){
        ctr++;
        copyn/=10;
    }
    // bs(1,10,n,1);
    bs(10,100,n,2,ctr);
    bs(100, 1000, n,3,ctr);
    bs(1000, 10000, n, 4,ctr);

    int p = anz.size();
    cout<< (p/2);
    loop(i,0,p){
        if(i%2==0)cout<<endl;
        cout<< anz[i]<<" ";
    }cout<<endl;

    anz.clear();
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