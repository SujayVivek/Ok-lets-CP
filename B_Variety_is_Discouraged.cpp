#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

void Solve() {
    int n; cin>>n;
    vector<int> a(n,0);
    map<int,int>mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    int i = 0, j = 0, len = 0;
    pair<int,int> ans;
    while(i<n && j<n){
        if(mpp[a[i]]==1){
            j = i+1;
            while(mpp[a[j]]==1 && j<n){
                j++;
            }
            if(j-i>len){
                len = j-i;
                ans = {i,j-1};
            }
            i = j;
        }else{
            i++;
        }
    }
    if(len==0){
        cout<<0<<endl;return;
    }
    cout<<ans.first+1<<" "<<ans.second+1<<"\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}