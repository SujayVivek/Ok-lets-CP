#include <bits/stdc++.h>
#define int long long
using namespace std;
main() {
    ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
    int t; cin >> t;
    while(t--) {
    	int n, k; 
		cin>>n>>k; 
		map<int,vector<int>> m;
    	for(int i=0; i<n; i++) { 
			int x; 
			cin>>x; 
			m[x%k].push_back(x/k);}
    	int c=0,s=0; 
    	for(auto i:m) { 
    		sort(i.second.begin(),i.second.end()); c+=i.second.size()%2;
    		int a=0;
    		for(int j=0; j<i.second.size()/2; j++) a+=i.second[j*2+1]-i.second[j*2];
    		int b=a;
    		if(i.second.size()%2) for(int j=i.second.size()-1; j>0; j-=2) b+=i.second[j]+i.second[j-2]-2*i.second[j-1], a=min(a,b); s+=a; }
    	if(c>1||c==1&&n%2==0) cout<<"-1\n"; else cout<<s<<"\n";
    }
}