
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
        int n;
        cin>>n;
        vi v(n,0);
        vi hash(n,0);
        FOR(i,n){
            cin>>v[i];
            
        }
        sort(v.begin(),v.begin()+n);
        if(v[0]==1 && v[1]==1){
            cout<<"NO"<<endl;
        }
        else if(v[0]==v[1]){int ctr=0;
            FOR(i,n){
                if(v[n-i-1]%v[0]==0){
                    ctr++;
                    // ctr++;cout<<"hi"<<ctr<<endl;
                }
            }
            if(ctr==n){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
        else{
            cout<<"YES"<<endl;
        }


    }
    return 0;

}