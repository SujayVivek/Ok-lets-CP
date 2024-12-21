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
    map<int,int>mpp; //map to store max time in each row
    vi ans;
    set<int>cols;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(s[(i*m)+j] == '1'){
                int R = mpp[i];
                mpp[i] = max(R,((i*m) + j) + m);
                cols.insert(j);
            }
            int col_contr = cols.size();
            int row_contr = 0;
            for(auto it: mpp){
                int x = it.second;
                if(x >=((i*m)+j) && x!=0) row_contr++;
            }
            ans.push_back(row_contr + col_contr);
        }
    }
    for(auto v: ans){
        cout<<v<<" ";
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