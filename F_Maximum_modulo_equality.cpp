#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff firsparseTable
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int N=2e5+5;
int a[N];
int sparseTable[N][31];
void Solve() {
    int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i) sparseTable[i][0]=a[i]-a[i-1];
	} 
	for(int j=1;j<20;j++)
	   for(int i=1;i<=n-(1<<j)+1;i++){
	   	sparseTable[i][j]=__gcd(sparseTable[i][j-1],sparseTable[i+(1<<(j-1))][j-1]);
	   }
	while(q--){
		int l,r;
		cin>>l>>r;r--;
		if(l>r) cout<<0<<" ";
		else{
			int len=log2(r-l+1);
			cout<<abs(__gcd(sparseTable[l][len],sparseTable[r-(1<<len)+1][len]))<<" ";
		}
	}cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}