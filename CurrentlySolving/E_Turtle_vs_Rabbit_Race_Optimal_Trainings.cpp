
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
        cin>>n;vi v(n,0);
        vi cumulative(n,0);
        FOR(i,n){
            cin>>v[i];
            if(i!=0){
                cumulative[i]=v[i]+cumulative[i-1];
            }
            else{
                cumulative[0]=v[0];
            }
        }
        int q;cin>>q;
        FOR(i,q){
            int l,u;cin>>l>>u;int mid;
            int high=n-1;int low=l-1;
            while(cumulative[low]<=cumulative[high]){
                mid=(low+high)/2;
                if(cumulative[mid]>=u){
                    high=mid-1;
                }
                else if(cumulative[mid]<u){
                    low=mid+1;
                }
            }
            cout<<mid+1<<" "; 
        }
        cout<<endl;

    }
    return 0;
}