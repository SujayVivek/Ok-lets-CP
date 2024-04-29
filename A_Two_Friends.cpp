
//   _______ _     _                     _        _        __             _   _            _                            
//  |__   __| |   (_)                   | |      (_)      / _|           | | | |          (_)                           
//     | |  | |__  _ ___    ___ ___   __| | ___   _ ___  | |_ ___  _ __  | |_| |__   ___   _ _ __  ___  __ _ _ __   ___ 
//     | |  | '_ \| / __|  / __/ _ \ / _` |/ _ \ | / __| |  _/ _ \| '__| | __| '_ \ / _ \ | | '_ \/ __|/ _` | '_ \ / _ \
//     | |  | | | | \__ \ | |_| (_) | |_| |  __/ | \__ \ | || (_) | |    | |_| | | |  __/ | | | | \__ \ |_| | | | |  __/
//     |_|  |_| |_|_|___/  \___\___/ \__,_|\___| |_|___/ |_| \___/|_|     \__|_| |_|\___| |_|_| |_|___/\__,_|_| |_|\___|
                                                                                                                     
#include <bits/stdc++.h>
using namespace std;                                                                                                                     
#define FOR(a,c)   for ( long long (a)=0; (a)<(c); (a)++)
typedef vector<long long> vi;
// typedef vector<long long> vll;
#define PB push_back
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        vi p(n,0);
        FOR(i,n){
            cin>>p[i];
            // p[i]=p[i]-1;
        }
        long long ctr=0;
        FOR(i,n){
            if(p[i]==p[p[i]]){
                ctr=1;break;
            }
        }
        if(ctr==1){
            cout<<"2"<<endl;
        }
        else{
            cout<<"3"<<endl;
        }
    }
    return 0;
}