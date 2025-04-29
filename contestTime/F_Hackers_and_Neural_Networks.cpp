#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n, m;cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<string>> b(m, vector<string>(n));
    for (int i = 0; i < m; i++) for(int j = 0; j<n; j++) cin>>b[i][j]; 
    vector<int> pres(n, 0); int mx = 0;
    for (int i = 0; i < m; i++) {
      int c = 0;
      for (int j = 0; j < n; j++) {
        if (a[j] == b[i][j]) {
          c++;
          pres[j] = 1;
        }
      }
      mx = max(mx, c);
    }
    for (int i = 0; i < n; i++) if(pres[i]==0){cout<<-1<<endl;return;} 
    cout <<n+2*(n-mx)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}