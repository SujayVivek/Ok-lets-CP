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
        int n, k;
        cin >> n >> k;
        string s;cin >> s;
        vi vss;
        int SUM = 0;
        for(int p = n-1; p >=0; p--){
            vss.push_back(SUM);
            if(s[p] == '1') SUM +=1;
            else SUM -=1;
        }
        sort(vss.begin(), vss.end(), greater<int>());


        int pref =0;
        int Ans = -1;

        for(int m=2; m<=n; m++){
            if(m-2 < vss.size()){
                pref += vss[m-2];
                if(pref >=k){
                    Ans = m; break;
                }
            }
        }
        cout << Ans << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}