#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[200010],k;
map<int,int>mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cin>>T;
	while(T--){
		cin>>n>>k;int ans=k-1;
		mp.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]=k-a[i]%k;
			if(a[i]!=k){
				mp[a[i]]++;
				ans=max(ans,mp[a[i]]*k+a[i]);
			}
		}cout<<ans-k+1<<"\n";
	}
	return 0;
}