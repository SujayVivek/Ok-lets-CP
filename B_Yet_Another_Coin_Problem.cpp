
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

int Solve(int n, vi &dp){
    int sum=0;
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    sum+=n/15+Solve(n%15,dp);
    sum-=n/15;
    sum+=n/10+Solve(n%10,dp);
    sum+=n/6+Solve(n%6,dp);
    sum+=n/3+Solve(n%3,dp);
    sum=n/1+Solve(0,dp);


}

int main(){
    int t;cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}