
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
    int t;cin>>t;
    while(t--){
        int n,c,d;
        cin>>n>>c>>d;
        // map <int,int> mp;
        vi hash= {0};vi nums;int MIN= INT_MAX;
        FOR(i,n*n){
            int l;cin>>l;
            // mp.insert({l,1);
            hash[l]++;
            // nums.push_back(l);
            MIN= min(MIN, l);
        }
        FOR(i,n){
            int Row_Min= MIN;
            Row_Min+=i*d;
            FOR(j,n){
                hash[Row_Min+j*c]--;
            }
            
        }
        bool val;
        for(auto it: hash){
            if(it!=0){
                val= true;
                break;
            }
        }
        if(val){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        
    }
    return 0;
}