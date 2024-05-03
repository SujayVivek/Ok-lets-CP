
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


int SolveBodya(int Pb,vi &p,vi &a,long long k){
    if(k==0){
        return 0;
    }
    int sum=0;int sum1=0,sum2=0;
    int newPos= p[Pb];
    sum1 = a[Pb]+ SolveBodya(newPos-1,p,a,k-1);
    sum2 = a[Pb] + SolveBodya(Pb,p,a,k-1);

    return max(sum1,sum2);
}
int SolveSasha(int Ps,vi &p,vi &a,long long k){
    if(k==0){
        return 0;
    }
    int sum=0;int sum1=0,sum2=0;
    int newPos= p[Ps];
    sum1 = a[Ps]+ SolveSasha(newPos-1,p,a,k-1);
    sum2 = a[Ps] + SolveSasha(Ps,p,a,k-1);

    return max(sum1,sum2);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,Pb,Ps;long long k;cin>>n>>k>>Pb>>Ps;
        vi p(n,0),a(n,0);
        FOR(j,n){
            cin>>p[j];
        }
        FOR(i,n){
            cin>>a[i];
        }
        int Bodya= SolveBodya(Pb-1,p,a,k);
        int Sasha= SolveSasha(Ps-1,p,a,k);

        if(Bodya>Sasha){
            cout<<"Bodya"<<endl;
        }
        else if(Bodya<Sasha){
            cout<<"Sasha"<<endl;
        }
        else{
            cout<<"Draw"<<endl;
        }
    }
    return 0;
}