#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

set<int> squares;
void Solve() {
    int n; cin>>n;
    vi a(n,0); int mx = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    vvi ans(n, vi(2,0));
    for(int i = 0; i<n; i++){
        int sq = sqrt(a[i]);
        if(sq*sq==a[i]) ans[i] = {0, a[i]};
        else{
            ans[i] = {min((sq+1)*(sq+1)-a[i], a[i]-sq*sq),a[i]};
        }
    }
    sort(ans.begin(), ans.end());
    int s = 0;
    for(int i = 0; i<ans.size()/2; i++){
        s+=ans[i][0];
    }
    if(s==0){
        for(int i = ans.size()/2; i<ans.size(); i++){
            if(ans[i][0]==0){
                int A = 0, B = 0, SQ = sqrt(ans[i][1]);int SQ1  = SQ;
                int copy1 = ans[i][1], copy2 = ans[i][1];
                while(SQ*SQ==copy1){
                    copy1++;A++;
                    SQ = sqrt(copy1);
                }
                while(SQ1*SQ1==copy2 && copy2>0){
                    copy2--; B++;
                    SQ1 = sqrt(copy2);
                }
                if(SQ1*SQ1!=copy2) s+= min(A,B);
                else s+= A;
            }
        }
    }
    cout<<s<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}