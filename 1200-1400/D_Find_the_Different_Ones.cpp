
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

void Solve(vll &v, ll l, ll r){
    
    if(r<=l) return;
    
    ll mid = (l+r)/2;
    if(v[mid]!=v[l]){
        
        cout<<l+1<<" "<<mid+1<<endl;
        return;
    }
    else if(v[mid]!=v[r]){
        cout<<mid+1<<" "<<r+1<<endl;
        return;
    }
    Solve(v, mid+1, r);
    Solve(v, l, mid-1);

    cout<<"-1"<<" "<<"-1"<<endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;cin>>n;
        vll v(n,0);
        FOR(i,n){
            cin>>v[i];
        }
        ll q;cin>>q;
        FOR(i,q){
            ll l,r;cin>>l>>r;
            Solve(v,l-1,r-1);
            
        }cout<<endl;
    }


return 0;
}