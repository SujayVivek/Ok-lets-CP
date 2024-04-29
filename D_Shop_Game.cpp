
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
        int n,k,ctr=0,sum=0,sum2=0;int Max=0;
        cin>>n>>k;
        vi v1(n,0);
        FOR(i,n){
            cin>>v1[i];
        }
        vi v2(n,0);
        vi v4,v3;
        FOR(i,n){
            cin>>v2[i];
        }
        FOR(i,n){
            if(v1[i]<v2[i]){
                ctr++;sum+=v2[i]-v1[i];
            }
            else{
                sum2+=v1[i]-v2[i];
                v3.push_back(v1[i]-v2[i]);
            }
            v4.push_back(v2[i]-v1[i]);
        }
        sort(v3.begin(),v3.end());
        sort(v4.begin(),v4.end());
        int sum3=0;
        if(ctr>=k){
            FOR(i,k){
                sum3+=v4[i];
            }
            cout<<sum<<endl;
        }
        else{
            cout<<sum-sum2<<endl;
        }
        
    }
    return 0;
}