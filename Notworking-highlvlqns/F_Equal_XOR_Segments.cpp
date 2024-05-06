
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

int xored(vi &v){
    int ans=v[0];
    for(int i=1;i<v.size();i++){
        ans^=v[i];
    }
    return ans;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        vi v(n,0);
        FOR(i,n){
            cin>>v[i];
        }
        while(q--){
            int l,r;cin>>l>>r;
            l--;r--;int ctr=-1;
            // --------Divide by 2---------
            for(int m=l+1;m<=r;m++){
                vi v1,v2;
                copy(v.begin()+l,v.begin()+m,v1.begin());
                copy(v.begin()+m,v.begin()+r,v2.begin());
                if(xored(v1)==xored(v2)){
                    ctr=1;break;
                }
            }
            if(ctr!=1){
            // ---------Divide by 3 segements------
                for(int m=l+1;m<=r-1;m++){
                    for(int k=m+1;k<=r;k++){
                        vi v1,v2,v3;
                        copy(v.begin()+l, v.begin()+m,v1.begin());
                        copy(v.begin()+m,v.begin()+k,v2.begin());
                        copy(v.begin()+k,v.begin()+r,v3.begin());
                        if(xored(v1)==xored(v2) && xored(v2)==xored(v3)){
                        ctr=1;break;
                        }   

                    }
                    if(ctr==1)break;
                }
                if(ctr==1)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
    
    return 0;
}