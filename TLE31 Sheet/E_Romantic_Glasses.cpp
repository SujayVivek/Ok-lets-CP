
//   _______ _     _                     _        _        __             _   _            _                            
//  |__   __| |   (_)                   | |      (_)      / _|           | | | |          (_)                           
//     | |  | |__  _ ___    ___ ___   __| | ___   _ ___  | |_ ___  _ __  | |_| |__   ___   _ _ __  ___  __ _ _ __   ___ 
//     | |  | '_ \| / __|  / __/ _ \ / _` |/ _ \ | / __| |  _/ _ \| '__| | __| '_ \ / _ \ | | '_ \/ __|/ _` | '_ \ / _ \
//     | |  | | | | \__ \ | |_| (_) | |_| |  __/ | \__ \ | || (_) | |    | |_| | | |  __/ | | | | \__ \ |_| | | | |  __/
//     |_|  |_| |_|_|___/  \___\___/ \__,_|\___| |_|___/ |_| \___/|_|     \__|_| |_|\___| |_|_| |_|___/\__,_|_| |_|\___|
                                                                                                                     
#include <bits/stdc++.h>
using namespace std;                                                                                                                     
#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back
#define ll long long

void Solve(){
    int n;cin>>n;
        vi v(n,0);
        FOR(i,n){
            cin>>v[i];
        }
        map <ll, ll> mp;
        ll s= 0;mp[0]= 1;
        FOR(i,n){
            ll p = v[i]*(i%2 ? -1: 1);
            s+= p;
            if(mp[s]){
                cout<<"YES"<<endl;
                return;
            }
            ++mp[s];
        }
        cout<<"NO"<<endl;
        return;
}

int main(){
    int t;cin>>t;
    while(t--){
        Solve();
    }
    
    return 0;
}