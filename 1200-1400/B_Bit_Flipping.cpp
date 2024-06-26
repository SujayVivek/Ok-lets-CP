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
    ll n,k;cin>>n>>k;
    // int ctr=-1;
    string s;
    cin>>s;
    vll ans(n,0);
    vll hash(n,0);
    
    if(k%2==0){
        ll j=0;
        while(k-- && j<n){
            if(s[j]=='1') {hash[j]=0; ans[j]=1;k++;}
            else{ hash[j]++; ans[j]=1;}

            j++;
        }ll copyj = j;
        if(j==n)k++;
         j=n-1;
        if(k>0){
            if(k%2==1){
                if(ans[j]==1){ans[j]=0; hash[j]+=k;}
                else if(ans[j]==0){ans[j]=1;hash[j]+=k;}
            }
            else{
                if(ans[j]==1){ans[j]=1; hash[j]+=k;}
                else if(ans[j]==0){ans[j]=0;hash[j]+=k;}
            }

            
        }
        while(copyj<n){
            ans[copyj]= (s[copyj]=='1'? 1:0);
            copyj++;
        }

    }
    else{
       ll j=0;
        while(k-- && j<n){
            if(s[j]=='1') {hash[j]++; ans[j]=1;}
            else{ hash[j]=0; ans[j]=1;k++;}

            j++;
        }ll copyj= j;
         if(j==n)k++; 
        j=n-1;
        if(k>0){
            if(k%2==1){
                if(ans[j]==1){ans[j]=0; hash[j]+=k;}
                else if(ans[j]==0){ans[j]=1;hash[j]+=k;}
            }
            else{
                if(ans[j]==1){ans[j]=1; hash[j]+=k;}
                else if(ans[j]==0){ans[j]=0;hash[j]+=k;}
            }

            
        }
        while(copyj<n){
            ans[copyj]= (s[copyj]=='1'? 0:1);
            copyj++;
        }
    }
    loop(i,0,n){
        cout<<ans[i];
    }cout<<endl;
    loop(i,0,n){
        cout<<hash[i]<<" ";
    }cout<<endl;

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
