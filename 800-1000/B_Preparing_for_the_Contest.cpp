#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            if(i<=k){
                cout<<i<<" ";
            }
            else{
                cout<<n+k-i+1<<" ";
            }
        }cout<<endl;
    }
    return 0;
}