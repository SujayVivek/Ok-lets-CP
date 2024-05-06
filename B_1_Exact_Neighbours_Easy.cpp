#include <bits/stdc++.h>
using namespace std;

#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back
#define ll long long

bool computation(const vector<int> &a, const vector<int>& b){
    if(a[0]==b[0]){
        return b[2]<a[2];
    }
    else{
        return a[0]<b[0];
    }
}


int main(){
    int n;cin>>n;
    int sum=0;vector<vector<int>>v(n,vector<int>(2));int l;
    FOR(i,n){
        cin>>l;
        sum+=l;
        v[i]={l,i+1};
    }
    sort(v.begin(),v.end());
    vector<vector<int>>ans(n,vector<int>(3));
    if(sum>=(n-1)*(n-2)/2){
        cout<<"YES"<<endl;
        ans[0]={1,1,1};
        for(int i=n-1;i>0;i--){
        //    cout<<"3"<<endl;
            ans[i]={v[i][1],i+1,v[i][0]-i+1};
        }          

        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            cout<<ans[i][1]<<' '<<ans[i][2]<<endl;
        }
        for(int i=0;i<n;i++){
            cout<<1<<' ';
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    

    return 0;
}
