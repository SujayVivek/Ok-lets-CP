#include <bits/stdc++.h>
using namespace std;
#define ll as long long
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int>A(n,0);
        vector<int>B(n,0);

        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            cin>>B[i];
        }
        long long ans=0, maxz=0;long long sum=0;
        for(int i=0;i<n && i<=k-1; i++){
            sum+=A[i];
            maxz=max(maxz,1ll*B[i]);
            ans= max(ans, sum+(1ll)*maxz*(k-i-1));


        }
        cout<<ans<<endl;
    }
    return 0;
}