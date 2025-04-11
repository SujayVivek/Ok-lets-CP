#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

pair<int,int> calc2(int S, int sz){
    int x = 1, y = 1;
    if(sz==1) return {x, y};
    int T = (S+(sz/2)*(sz/2)-1)/((sz/2)*(sz/2));
    if(T==1) {
        x = 1, y = 1;
    }else if(T==2){
        x = sz/2 + 1, y = sz/2 + 1;
        
    }else if(T==3){
        y = 1, x = sz/2 + 1;
    }else{
        x = 1, y = sz/2 + 1;
    }
    pair<int,int> ans = calc2(S-(T-1)*(sz/2)*(sz/2), sz/2);
    x+= ans.first-1, y+= ans.second-1;
    return {x, y};
}
int calc1(int a, int b, int startx, int starty, int sz){
    int ans = 0;
    if(sz==0) return ans;
    // cout<<a<<" "<<b<<" "<<startx<<" "<<starty<<" "<<sz<<" "<<endl;
    if(a-startx+1 < sz/2+1){
        if(b-starty+1<sz/2+1){
            ans+= calc1(a, b, startx, starty, sz/2);
        }else{
            ans+= 3*(sz/2)*(sz/2) + calc1(a, b, startx, starty+sz/2, sz/2);
        }
    }else{
        if(b-starty+1<sz/2+1){
            ans+= 2*(sz/2)*(sz/2) + calc1(a, b, startx+sz/2, starty, sz/2);
        }else{
            ans+= (sz/2)*(sz/2) + calc1(a, b, startx+sz/2, starty+sz/2, sz/2);
        }
    }return ans;
}
void Solve() {
    int n; cin>>n;
    n = 1<<n;
    int q; cin>>q;
    while(q--){
        string s; cin>>s;
        if(s=="->"){
            int a, b; cin>>a>>b;
            cout<< calc1(a,b, 1, 1, n)+1<<endl;
        }else{
            int S; cin>>S;
            pair<int,int> ans = calc2(S, n);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}