#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"


const int N = 1e5+10;
vi g[N];
vector<bool> vis(N,0);
vector<int> par(N,-1);
 
void dfs(int node,int p)
{
      par[node] = p;
      vis[node] = 1;
    
      for(auto x : g[node])
          if(!vis[x]) dfs(x,node);
          else if(x != p)
      {
          vector<int> cyc;   
          
          int cur = node;
         
          cyc.push_back(node);
          
          while(par[cur] != x)
          {
             cur = par[cur];
             cyc.push_back(cur);
          }
          
          cyc.push_back(x);
          cyc.push_back(node);
          
          cout << cyc.size() << '\n';
          
          for(auto x : cyc) cout << x <<" ";
          exit(0);
      }
}
 
void Solve()
{
  int n,m;
    cin >> n >> m;
    
  int a,b;
    
 for(int i = 0; i<n; i++)
  {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
    
    
  for(int i=1;i<=n;i++)
      if(!vis[i])
  dfs(i,-1);
    
  cout<<"IMPOSSIBLE\n";
    
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
