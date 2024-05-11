
//   _______ _     _                     _        _        __             _   _            _                            
//  |__   __| |   (_)                   | |      (_)      / _|           | | | |          (_)                           
//     | |  | |__  _ ___    ___ ___   __| | ___   _ ___  | |_ ___  _ __  | |_| |__   ___   _ _ __  ___  __ _ _ __   ___ 
//     | |  | '_ \| / __|  / __/ _ \ / _` |/ _ \ | / __| |  _/ _ \| '__| | __| '_ \ / _ \ | | '_ \/ __|/ _` | '_ \ / _ \
//     | |  | | | | \__ \ | |_| (_) | |_| |  __/ | \__ \ | || (_) | |    | |_| | | |  __/ | | | | \__ \ |_| | | | |  __/
//     |_|  |_| |_|_|___/  \___\___/ \__,_|\___| |_|___/ |_| \___/|_|     \__|_| |_|\___| |_|_| |_|___/\__,_|_| |_|\___|
                                                                                                                     
#include <bits/stdc++.h>
using namespace std;                                                                                                                     
#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
#define FORI(a,c)   for ( int (a)=1; (a)<(c); (a)++)
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        int n,k,q;cin>>n>>k>>q;
        vi va(k+1,0), vb(k+1,0);
        vi Times_before(k,0);
        for(int i=1;i<k+1;i++){
            cin>>va[i];
        }
        va[0]=0;vb[0]=0;
        int sum=0;
        for(int i=1;i<k+1;i++){
            int l;
            cin>>l;
            vb[i]=l;
            sum+=l;
            Times_before[i]=sum;
        }
        FOR(i,q){
            int d;cin>>d;
            int j=0;
            int time=0;
            while(1){
                if(d<va[j]){
                    break;
                }
                time+=vb[j];
                j++;
                
            }
            j--;
            int ans= time- vb[j] + floor(((vb[j+1]-vb[j])*(d-va[j]))/(va[j+1]-va[j])); 
            cout<<ans<<" ";
        }
        cout<<endl;
        
    }
    
    return 0;
}