
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

void Solve(int ind,vi &ds1,vi &ds2,int n){
    static int minz=INT_MAX;
    if(ind==n){
        int price=0;
        FOR(i,ds1.size()-1){
            if(ds1[i]<ds1[i+1]){
                price++;
            }
        }
        FOR(i,ds2.size()-1){
            if(ds2[i]<ds2[i+1]){
                price++;
            }
        }
        minz=min(price,minz);
        return;
    }
     Solve(ind+1,ds1,ds2,n);
     ds2.push_back(ds1[ind]);
     ds1.pop_back();
     Solve(ind+1,ds1,ds2,n);

    cout<<minz<<endl;
    return;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(auto &x:arr){
            cin>>x;
        }
        vi ds2;
        Solve(0,arr,ds2,n);
    }
    return 0;
}