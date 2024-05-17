
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
        int p1,p2,p3;
        cin>>p1>>p2>>p3;
        int sum = p1+p2+p3;
        if(sum%2==1){
            cout<<"-1"<<endl;
            continue;
        }
        else{
            int maxp = max(p1,p2);
            maxp = max(maxp, p3);
            int minp = min(p1,p2);
            minp = min(minp,p3);
            int num2 = sum- maxp- minp;
            priority_queue <int> pq;
            pq.push(maxp);
            pq.push(minp);
            pq.push(num2);
            int ctr=0;
            while(pq.top()!=0){
                int l = pq.top(); pq.pop();
                int r= pq.top();pq.pop();
                if(l==0 || r==0)break;
                pq.push(l-1);pq.push(r-1);
                ctr++;
            }
            cout<<ctr<<endl;
        }

    }
    
    return 0;
}