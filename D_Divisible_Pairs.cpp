
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

int Checker(int a,int b,int x, int y){
    if((a+b)%x == 0 && (abs(a-b))%y ==0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int t;cin>>t;
    while(t--){int ctr=0;
        int n,x,y;cin>>n>>x>>y;
        vi ve, vo;
        FOR(i,n){
            int l;
            cin>>l;
            if(l%2==0)ve.push_back(l);
            else vo.push_back(l);
        }
        sort(ve.begin(), ve.end());
        sort(ve.begin(), ve.end());
        if(x%2==0){
            //use only the even array
            // int ctr=0;
            int sz= ve.size();
            // int j=1,i=0;
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(ve[i]+ ve[j]< x || abs(ve[i] - ve[j])<y){
                        continue;
                    }
                    if(Checker(ve[i], ve[j], x, y)){
                        ctr++;
                    }
                }
            }
        }
        else if(x%2!= 0){
            int p= ve.size(), q= vo.size();
            int i=0,j=0;
            for(int i=0;i<p;i++){
                for(int j=0;j<q;j++){
                    if(ve[i]+ vo[j]< x || abs(ve[i] - vo[j])<y){
                        continue;
                    }
                    if(Checker(ve[i], vo[j], x, y)){
                        ctr++;
                    }
                }
            }  
        }
        cout<<ctr<<endl;

    }
    
    return 0;
}