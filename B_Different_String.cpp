
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
        
      string s;cin>>s;
      int n=s.length();
      vi v;
      if(s.length()<=1){
        cout<<"NO"<<endl;
        continue;
      }  
      else{
        char a= s[0];int ctr=-1;
        for(int i=1;i<s.length();i++){
            if(a!=s[i]){
                cout<<"YES"<<endl;ctr++;
                cout<<s[i];
                for(int j=1;j<n;j++){
                    if(i==j){
                        cout<<a;continue;
                    }
                    cout<<s[j];
                }cout<<endl;
                break;
            }
        }
        if(ctr==-1)cout<<"NO"<<endl;
      }
    }
    
    return 0;
}