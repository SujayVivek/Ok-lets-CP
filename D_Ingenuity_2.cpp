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
    int n;cin>>n;
    string s;cin>>s;
    map <char, int> mapp;
    loop(i,0,n){
        mapp[s[i]]++;
    }
    map <int, char> mapp2;
    if((mapp['S']+ mapp['N'])%2==0 && (mapp['E']+ mapp['W'])%2==0){
        if(mapp['S']>= mapp['N']){
            if(mapp['E']> mapp['W']){
                //all N goes to R & all W goes to R
                int a= mapp['N'], b= mapp['W'];int ctra=0, ctrb=0;
                loop(i,0,n){
                    if(s[i]=='N' && a!=0){
                        mapp2[i]= 'R';
                    }
                    else if(s[i]=='W' && b!=0){
                        mapp2[i]=='R';
                    }
                    
                    else if(s[i]=='S'){
                        if(a==0)
                        {mapp2[i]= (ctra%2==0?'H':'R');ctra++;}
                        else{
                            mapp2[i]='R';
                        }
                    }

                    else {
                        if(b==0)
                        {mapp2[i]==(ctrb%2==0? 'H':'R');ctrb++;}
                        else{
                            mapp2[i]='R';
                        }
                        
                    }
                    
                }
            }
            else{
                int a= mapp['N'], b= 2*mapp['E'];int ctra=0, ctrb=0;
                loop(i,0,n){
                    if(s[i]=='N' && a!=0){
                        mapp2[i]= 'R';a--;
                    }
                    else if((s[i]=='E')  && b!=0){
                        mapp2[i]=='R';b--;
                    }
                    else if(s[i]=='S'){
                        if(a==0)
                        {mapp2[i]= (ctra%2==0?'H':'R');ctra++;}
                        else{
                            mapp2[i]='R';
                        }
                        }
                    else {
                        if(b==0)
                        {mapp2[i]==(ctrb%2==0? 'H':'R');ctrb++;}
                        else
                        mapp2[i]=='R';
                    
                    }
                    
                }
            }
        }
        else{
            if(mapp['E']> mapp['W']){
                //all S goes to R & all W goes to R
                int a= mapp['S'], b= mapp['W'];int ctra=0, ctrb=0;
                loop(i,0,n){
                    if(s[i]=='S' && a!=0){
                        mapp2[i]= 'R';a--;
                    }
                    else if(s[i]=='W' && b!=0){
                        mapp2[i]=='R';b--;
                    }
                    
                    else if(s[i]=='N')
                    {   if(a==0){
                        mapp2[i]= (ctra%2==0?'H':'R');ctra++;}
                        else{
                            mapp2[i]='R';
                        }
                    }
                    else if(s[i]=='E') {
                        if(b==0){
                        mapp2[i]==(ctrb%2==0? 'H':'R');ctrb++;}
                        else{
                            mapp2[i]='R';
                        }
                        }
                    
                }
            }
            else{
                int a= mapp['S'], b= mapp['E'];int ctra=0, ctrb=0;
                loop(i,0,n){
                    if(s[i]=='S' && a!=0){
                        mapp2[i]= 'R';
                    }
                    else if(s[i]=='E' && b!=0){
                        mapp2[i]=='R';
                    }
                    else if(s[i]=='N'){
                        if(a==0){
                        mapp2[i]= (ctra%2==0?'H':'R');ctra++;}
                        else{
                            mapp2[i]='R';
                        }
                        }
                    else if(s[i]=='E') {
                        if(b==0){
                        mapp2[i]==(ctrb%2==0? 'H':'R');ctrb++;}
                        else{
                            mapp2[i]='R';
                        }
                        }
                    
                }
            }
        }
        for(auto it: mapp2){
            cout<<it.second;
        }
        cout<<endl;
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
