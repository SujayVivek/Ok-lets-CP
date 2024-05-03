
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

bool sortbyfirstelement(vector<int>&a, vector<int>&b){
    return a[0]<b[0];
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vi a(n),b(n); vector<vector<int>> profit_a,profit_b;
        FOR(i,n){
            cin>>a[i];
        }
        FOR(i,n){
            cin>>b[i];
        }
        FOR(i,n){
            if(a[i]>=b[i]){
                profit_a.push_back({a[i]-b[i],a[i]});
            }
            else{
                profit_b.push_back({b[i]-a[i],a[i]});
            }
        }
        sort(profit_a.begin(),profit_a.end(),sortbyfirstelement);
        if(profit_a.size()>=k){
            for(int i=k;i<profit_a.size();i++){
                
            }
        }
    }
    return 0;
}