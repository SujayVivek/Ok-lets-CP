
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
        int n;cin>>n;
        vi v(n,0);
        FOR(i,n){
            cin>>v[i];
        }
        int k=1;
        while(k<=n){
            set <int> st;
            for(int i=0;i<n-k;i++){
                int ans= v[i];

                for(int j=i+1;j<i+k;j++){
                    ans = ans | v[j];
                }
                st.insert(ans);

            }
            if(st.size()==1 && n!=1){
                break;
            }
            k++;
        }k--;
        if(k<=1){
            cout<<k+1<<endl;
        }
        else{
            cout<<k+2<<endl;
        }
        
    }

    
    return 0;
}