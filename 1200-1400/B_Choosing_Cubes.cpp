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
    int n,f,k;
    cin>>n>>f>>k;
    // if(n==k){
    //     cout<<"YES"<<endl;
    //     return;
    // }
    vi v(n,0);
    int value = 0;
    loop(i,0,n){
        cin>>v[i];
        if(i== f-1){
            value = v[i];
        }
    }
    sort(all(v), greater<int>());
    // cout<<"VALUE  +"<<value<<endl;
    if(n==k){cout<<"YES"<<endl;return;}
    if(v[k-1]>value){
        cout<<"NO"<<endl;
    }
    else if(v[k-1]<value){
        cout<<"YES"<<endl;
    }
    else if(v[k-1]==value && (k!=n && v[k]!=value)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"MAYBE"<<endl;
    }
    return;
}

int32_t main() {
    auto begin = chrono::high_resolution_clock::now();

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
