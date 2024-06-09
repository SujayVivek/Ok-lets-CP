
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


ll fact(ll a, vll &dp){
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    ll copy = a-1;
    ll prod= a;
    while(copy>=1){
        if(dp[copy]!=-1){
            prod*= dp[copy];
            break;
        }
        prod*= copy;
        copy--;
    }
    dp[a]= prod;
    return prod;
}
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll n= s.length();
        vll v;
        ll k=1;
        FOR(i,n-1){
            if(s[i]!=s[i+1]){
                v.push_back(k);
                k=1;
            }
            else{
                k++;
            }
        }
        v.push_back(k);
        ll p = v.size();
        ll prod=1;int ctr=0;
        vll dp(n+5,-1);
        if(p==0){
            cout<<n-1<<" "<<fact(n, dp)<<endl; continue;
        }
        FOR(i,p){
            
           
            prod*= fact(v[i], dp);

            if(v[i]>1){
            ctr+= v[i]-1;
            }
           
            
        }
        if(p!=0)
        cout<<ctr<<" "<<prod<<endl;
    }
    
    return 0;
}