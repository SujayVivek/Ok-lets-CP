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

    int n;cin>>n;
    string s;cin>>s;
    map <char, int> mapp;
    loop(i,0,n){
            if(s[i]=='N'){
                mapp['N']++;
            }
            else if(s[i]=='S'){
                mapp['N']--;
            }
            else if(s[i]=='W'){
                mapp['W']++;
            }
            else{
                mapp['W']--;
            }
    }
        map <int, char> ans2;int ctr1=0,ctr2=0;
        if(s.length()==2 && (mapp['W']==0 && mapp['N']==0)){cout<<"NO"<<endl;return;}

        if(s[0]=='N' || s[0]=='S'){
            ans2[0]= 'R';ctr1=1;
        }
        else{
            ans2[0]='R';
            ctr2=1;
        }
        if(abs(mapp['N'])%2==0 && abs(mapp['W'])%2==0 ){
            mapp['N']= abs(mapp['N'])-ctr1; mapp['W']= abs(mapp['W'])-ctr2;
            loop(i,1,n){
                mapp['N']= abs(mapp['N']); mapp['W']= abs(mapp['W']);
                if((s[i]=='N' || s[i]=='S') && mapp['N']!=0){
                    if(ctr1)
                    ans2[i]= (mapp['N']%2? 'H':'R'); mapp['N']--;
                    

                }
                else if((s[i]=='W' || s[i]=='E') && mapp['W']!=0){
                    ans2[i]= (mapp['W']%2? 'H':'R'); mapp['W']--;
                }
                else{
                    ans2[i]='H';
                }
            }
            for(auto it: ans2){
                cout<<it.second;
            }cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
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
