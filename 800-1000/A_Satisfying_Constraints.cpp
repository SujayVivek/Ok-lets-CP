
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
        int n;
        cin>>n;
        int Min=INT_MAX,Max=0;
        stack<int>st;
        FOR(i,n){
            int a,x;cin>>a>>x;
            if(a==1){
                Max=max(x,Max);
            }
            else if(a==2){
                Min=min(x,Min);    
            }
            else if(a==3){
            st.push(x);
            }
        }
            int ctr=0;
          while(!st.empty()) {
            if(st.top()>=Max && st.top()<=Min){
                ctr++;
            }
            st.pop();
          } 
          if(Min<Max){
            cout<<0<<endl;
          }
          else{
            cout<<abs(Min-Max)+1-ctr<<endl;

          }
    }
    return 0;
}