#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],b[N];
 
void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	
	ll sum_a=0,sum_b=0;
	
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum_a+=a[i];
	}
	for (int i=1;i<=m;i++){
		cin>>b[i];
		sum_b+=b[i];
	}
	
	sort(b+1,b+n+1);
	
	set<ll > vis_a,vis_b;
	for (int i=1;i<=n;i++){
		vis_a.insert(sum_a-a[i]);
	}
	
	for (int i=1;i<=m;i++){
		vis_b.insert(sum_b-b[i]);
	}
	
	ll x;
	while (q--){
		bool bol=false;
		cin>>x;
		int xx=abs(x);
		for (int i=1;i<=sqrt(xx);i++){
			if (x%i==0){
//				cout<<i<<" "<<x/i<<"\n";
				if (vis_a.count(i) && vis_b.count(x/i)) bol=true;
				if (vis_b.count(i) && vis_a.count(x/i)) bol=true;
				
				ll ii=-i,iii=x/ii;
				if (vis_a.count(ii) && vis_b.count(iii)) bol=true;
				if (vis_b.count(ii) && vis_a.count(iii)) bol=true;				
				
				if (bol) break;
			}
		}
		
		if (bol) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
 
int main(){
	int t;
	t=1;
	while (t--){
		solve();
	}
	return 0;
} 