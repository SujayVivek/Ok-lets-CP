
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

ll Solve(ll n,ll sum,vll &dp){

    if(n==0){
        
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n>=15){
        sum+=n/15;
        sum+=Solve(n%15,sum,dp);  
    }
    else if(n<15 && n>=10){
        sum+=n/10;
        sum+=Solve(n%10, sum,dp);
    }
    else if(n<10 && n>=6){
        sum+=n/6;
        sum+=Solve(n%6,sum,dp);
    }
    else if(n<6 && n>=3){
        sum+=n/3;
        sum+=Solve(n%3,sum,dp);
    }
    else{
        sum+=n/1;
        sum+=Solve(n%1,sum,dp);
    }
    dp[n]=sum;
    return sum;
}

int main(){
    int t;cin>>t;vll dp(15,-1);
    while(t--){
        ll n;cin>>n;
        ll sum=0;
        ll ans= Solve(n,sum,dp);
        cout<<ans<<endl;
    }
    return 0;
}