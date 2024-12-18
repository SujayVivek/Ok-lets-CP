#include<bits/stdc++.h>
using namespace std;const int N=1e5+5;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q,t,x,y,z,w;
	int rows[N]={0},column[N]={0};
	set<int> a;
	set<int>b;
	cin>>n>>q;
	for(int i=1;i<=n+1;i++){a.insert(i);b.insert(i);}
	while(q--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>x>>y;
			rows[x]++;
			column[y]++;
			if(rows[x]==1)a.erase(x);
			if(column[y]==1)b.erase(y);
		}
		else if(t==2)
		{
			cin>>x>>y;
			rows[x]--;
			column[y]--;
			if(rows[x]==0)a.insert(x);
			if(column[y]==0)b.insert(y);
		}
		else
		{
			cin>>x>>y>>z>>w;
			if(z>=*a.lower_bound(x)&&w>=*b.lower_bound(y))cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	return 0;
}