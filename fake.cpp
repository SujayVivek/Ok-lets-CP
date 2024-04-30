
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

const int N = 1e6+5;
int arr[N], b[N];
void problemA(){
    int n;cin>>n;
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int count =0;
    while(1){
        sort(arr+1,arr+1+n);
        bool check= true;
        for(int i=1;i<=n;i++){
            if(arr[i]>b[i]){
                check= false;
                break;
            }
            
        }
        if(check==true)break;

            arr[n]=0;
            count++;
    }
    cout<<count<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        problemA();
    }
    return 0;
}