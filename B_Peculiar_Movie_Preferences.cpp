#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
const int N=1e5+10;
int n;
string a[N],b[N];
set<string> s;
bool solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i],b[i]=a[i];
		reverse(b[i].begin(),b[i].end());
	}
	s.clear();
	for(int i=1;i<=n;++i){
		s.insert(a[i]);
		if(s.find(b[i])!=s.end())return 1;
		if(b[i].length()==3){
			if(s.find(b[i].substr(0,2))!=s.end())return 1;
		}
	}
	s.clear();
	for(int i=n;i;--i){
		s.insert(a[i]);
		if(b[i].length()==3){
			if(s.find(b[i].substr(1,2))!=s.end())return 1;
		}
	}
	return 0;
}
int32_t main(){
	int T;
	cin>>T;
	while(T--)cout<<(solve()?"YES":"NO")<<'\n';
}