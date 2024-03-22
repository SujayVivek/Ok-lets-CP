
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
    int t;
    cin>>t;
    while(t--){
        
    long long a, b, l;
    cin >> a >> b >> l;

    set <long long> st;
    long long x= floor(log(l)/log(a));
    long long y= floor(log(l)/log(b));

    for(int i=0;i<=x+1;i++){
        for(int j=0;j<=y+1;j++){
            long long  p= pow(a, i) * pow(b, j);
            int k= l/p;
            
            if(k*p==l){
                st.insert(k);
                // cout<<k<<endl;
            }
            
        }
    }
    cout<<st.size()<<endl;
    

    }
    return 0;
}