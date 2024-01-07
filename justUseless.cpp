
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
#define ll long long

int SolveCalc(vi &v,vi &v2,int p,int n){
    int price=0;
    FOR(i,n-p-1){
        if(v[i]<v[i+1]){
            price++;
        }
    }  

    FOR(i,p-1){
        if(v2[i]<v2[i+1]){
            price++;
        }
    }

    return price;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v(n,0);
        int mini=INT_MAX;int MinIndex=0;
        FOR(i,n){
            cin>>v[i];
            if(mini>v[i]){
                mini=v[i];
                MinIndex=i;
            }
        }
        int i=0;int p=0;
        vi v2;int l=1;
        while(i<MinIndex){
            if((v[i+1]<v[i]) || l==0){
               i++; l=1;
            }
            else{
                p++;
                v2.push_back(v[i+1]);
                v.erase(v.begin()+i+1);
                l=0;
            }
        }
        for(int i=MinIndex+1;i<n;i++){
            v2.push_back(v[i]);
            v.erase(v.begin()+i);
        }
        int ans=SolveCalc(v,v2,p,n);
        cout<<ans<<endl;
    }
    return 0;
}