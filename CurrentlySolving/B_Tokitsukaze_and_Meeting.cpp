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
    int n, m; cin>>n>>m;
    string s; cin>>s;
    set<int>cols;
    vi rows((n+2)*m, 0);
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='1'){
            int j = i;
            while(j<s.length()){
                rows[j]++;
                if(j+n<s.length())rows[j+n]--;
                j+=n+1;
            }
        }
    }
    for(int i = 1; i<rows.size(); i++){
        rows[i]+= rows[i-1];
    }
    vi ans;
    int k = 0;
    for(int i = 0; i<n; i++){
        bool ok = false;
        for(int j = 0; j<m; j++){
            if(j==m-1)k++;
            int row_contr = (rows[i+j+k] + 3)/4;
            cols.insert(j);
            int cols_contr = cols.size();
            ans.push_back(row_contr + cols_contr);
        }
    }
    for(auto x: ans){
        cout<<x<<" ";
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