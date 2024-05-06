
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

#include<bits/stdc++.h>
using namespace std;
long long score(vector<int>&p,vector<int>&a,int s,int k){
	int n=p.size();
	long long mx=0,cur=0;
	vector<bool>vis(n);
	while(!vis[s]&&k>0){
		vis[s]=1;
		mx=max(mx,cur+1ll*k*a[s]);
		cur+=a[s];
		k--;
		s=p[s];
	}
	return mx;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,s1,s2;
		cin>>n>>k>>s1>>s2;
		vector<int>p(n),a(n);
		for(auto&e:p){
			cin>>e;
			e--;
		}
		for(auto&e:a){
			cin>>e;
		}
		long long A=score(p,a,s1-1,k),B=score(p,a,s2-1,k);
		cout<<(A>B?"Bodya\n":A<B?"Sasha\n":"Draw\n");
	}
}