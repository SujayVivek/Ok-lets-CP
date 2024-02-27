
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


void Solve(){
    int n,m,k;cin>>n>>m>>k;int ctr=0;long long SUM=0;vi confirm(k,-1);
    // vi v1(n,0),v2(m,0);
    int l;
    vi hash(k,INT_MAX);
    FOR(i,n){
        cin>>l;
        if(l<=k){
            hash[l-1]=1;
        }

    }
    // cout<<"HI"<<endl;
    // FOR(i,k){
    //     cout<<hash[i]<<"\t";
    // }
    FOR(i,m){
        cin>>l;
        if(l<=k){
            if(hash[l-1]==1 || confirm[l-1]==100){
                confirm[l-1]=100;
                hash[l-1]=0;
            }
            else{
                hash[l-1]=-1;
            }
        }
    }
    // cout<<"HI"<<endl;
    // FOR(i,k){
    //     cout<<hash[i]<<"\t";
    // }

    FOR(i,k){
        SUM+=hash[i];
        if(hash[i]==0){ctr++;}
        // cout<<hash[i];
    }
    // cout<<ctr<<endl;
    if(abs(SUM)<=ctr || SUM==0){
        cout<<"YES"<<endl;
    }   
    else{
        cout<<"NO"<<endl;
    }
    return;
}
int main(){
    int t;cin>>t;while(t--){
        Solve();
    }
    return 0;
}