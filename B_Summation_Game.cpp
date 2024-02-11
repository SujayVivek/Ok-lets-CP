
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
#define PB push_back

int main(){
    int t;cin>>t;
    while(t--){
        int n,k,x;cin>>n>>k>>x;
        vi v(n,0),hash(n,0);int sum=0;
    FOR(i,n){
        cin>>v[i];   
    }    
    // cout<<"hi";
    map <int,int> mp;int Max=0;int ans=0;
    sort(v.begin(),v.begin()+n);
    FOR(i,n){
        sum+=v[i];hash.PB(sum);
    }
    // cout<<"hi";
    if(k<x){
        cout<<0<<endl;
    }
    else{
        while(k!=0){
            // Max=max(Max,2*hash[k-x]-hash[k]);
            if(Max<(2*hash[k-x]-hash[k])){
                Max=2*hash[k-x]-hash[k];
                ans=k;
            }

            k--;
        }
        cout<<Max<<endl;
    }
    }
    
    return 0;
}