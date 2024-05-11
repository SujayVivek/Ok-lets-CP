
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
        int n,k;cin>>n>>k;
        vector<vi> v(n,vi(2));
        // int MIN= INT_MAX:
        int l;
        FOR(i,n){
            cin>>l;
            v[i]= {l,i+1};
        }
        sort(v.begin(),v.end());
        int ctr=1,j=0;int level= v[0][0];
        while(k>0 && j<n-1){
            if((k/ctr)>(v[j+1][0]-v[j][0])){
                k-=(v[j+1][0]-v[j][0])*ctr;
                level+= (k/ctr);
                ctr++;j++;
            }
            else{
                level+= (k/ctr);
                k-=k/ctr;
                break;
            }
        }
        // cout<<" "<<k<<endl;
        cout<<level+ (level-1)*(n-1) +k<<endl;

    }
    
    return 0;
}
