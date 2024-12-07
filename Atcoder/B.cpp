#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int check(int i, int j, int k, int l, vector<vector<char>>&v, int D){
    vvi hash(v.size(), vi(v[0].size(), 0));
    int cnt = 0;
    for(int p = 0; p<v.size(); p++){
        for(int q = 0; q<v[0].size(); q++){
            if(v[p][q]!='#'){
                if((abs(p-i) + abs(q-j)) <= D && hash[p][q]!=1){
                    cnt++; hash[p][q] = 1;
                }
                if((abs(p-k) + abs(q-l)) <=D && hash[p][q]!=1){
                    cnt++; hash[p][q] = 1;
                }
            }
        }
    }
    return cnt;
}
void Solve() {
    int H, W, D;
    cin>>H>>W>>D;
    vector<vector<char>> v(H, vector<char>(W, 0));
    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            cin>>v[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i<H; i++){
        for(int k= 0; k<H; k++){
            for(int j = 0; j<W; j++){
                for(int l = 0; l<W; l++){
                    if(v[i][j]!='#' && v[k][l]!='#')
                    ans = max(ans, check(i, j, k, l, v, D));
                }
            }
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}