
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

int main(){
    int t;cin>>t;vll dp(15,-1);
    while(t--){
       ll n;cin>>n;ll sum=0;
        while(n!=0){
            if(n<15){
                if(dp[n]!=-1){
                sum+=dp[n];
            }
            else{
                if(n>=15){
                sum+=n/15;
                n=n%15;
                }
                else if(n<15 && n>=10){
                sum+=n/10;
                n=n%10;
                }
                else if(n<10 && n>=6){
                sum+=n/6;
                n=n%6;
                }
                else if(n<6 && n>=3){
                sum+=n/3;
                n=n%3;
                }
                else{
                sum+=n/1;
                n=n%1;
                }
                }
            }
            else{
                sum+=n/15;
                n=n%15;
            }
            
            dp[n]=sum;
        }
        cout<<sum<<endl;
    }
    return 0;
}