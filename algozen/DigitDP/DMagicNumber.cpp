#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int MOD=1e9+7;
 
int dp[2001][2001][2][2];
bool vis[2001][2001][2][2];
 
string A,B;
int M,D;
 
int calc(int pos,int rem,int ql,int qr){
  if(pos==A.size()) return rem==0;
  if(vis[pos][rem][ql][qr]) return dp[pos][rem][ql][qr];
  vis[pos][rem][ql][qr]=true;
    int ans=0;
  for(int c='0';c<='9';c++){
    if(!ql&&c<A[pos]) continue;
    if(!qr&&c>B[pos]) continue;
    if((pos%2)^(c-'0'==D)) continue;
    ans=(ans+calc(pos+1,(rem*10+(c-'0'))%M,ql||c>A[pos],qr||c<B[pos]))%MOD;
  }
  return dp[pos][rem][ql][qr]=ans;
}

void Solve(){
    cin>>M>>D>>A>>B;
    cout<< calc(0,0,0,0)<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}