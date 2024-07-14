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

long long Solvez(vi &a, string s){
    ll p = s.length();
    ll j = 0;ll sum = 0;ll prod = 1;ll z = 0;ll ct =0;ll anz = 0;
    loop(i,0,p){
        prod = 1;
        if(s[i]==a[j]){
            if(ct==0)z = i; //maybe have to introduce another var here
            ct++;
            ll p=0;
            while(s[i]==a[j]){
                p++;i++;
            }i--;
            prod*=p;
            j++;
            // i+=p;
        }
        sum+=prod;
        if(j==4){anz+=sum;i = z;ct = 0;j = 0;}
        
    }
    ll prime = 1e9+7;
    return anz%prime;

}
ll ncr(int n, int r){
    ll prodN = 1, prodD = 1;
    loop(i,0,r){
        prodN *= n-i;
        prodD = i+1; 
    }
    ll q = prodN/prodD;
    ll prime = 1e9+7;
    return q%prime;
}
long long Solver(vvi &a, string s){
    int p = s.length();
    vvi v;
    loop(i,0,p-1){
        int t = 1;
        if(s[i]==s[i+1]){
            t++;
        }else{
            v.push_back({s[i]-'0',t} );
        } 
    }
    int q = v.size();ll sum = 0;int j = a.size();
    loop(i,0,q){
        if(v[i][0] == a[j][0]){
            int k = i;int prod = 1;
            j = a.size();
            while(j--){
                prod*= ncr(v[k][1],a[k][1]);
                k++;
            }
            sum+= prod;
        }

    }
    return sum;

}
void Solve() {
    // Your code for each test case goes here
    string s;cin>>s;

    vvi a1 = {{1,1},{0,1},{1,1},{0,1},{1,1}};
    vvi a2 = {{0,1},{1,1},{0,1},{1,1},{0,1}};
    vvi a3 = {{1,1},{0,1},{1,1}};
    vvi a4 = {{0,1},{1,1},{0,1}};
    ll prime = 1e9+7;
    cout<<  (Solver(a1, s)+ Solver(a2 ,s)+ Solver(a3 , s)+ Solver(a4 ,s))%prime;
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