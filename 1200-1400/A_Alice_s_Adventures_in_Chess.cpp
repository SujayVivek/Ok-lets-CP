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
    int n, a, b;cin>>n>>b>>a;
    string s; cin>>s;
    if(a==0 && b==0) {cout<<"YES"<<endl; return;}
    int Up = 0, Right = 0;
    int c =0;
    while(c<=20){
        for(int i = 0; i<n; i++){
            if(s[i]=='N')Up++;
            else if(s[i]=='S')Up--;
            else if(s[i]=='E')Right++;
            else Right--;

            if(Up==a && Right==b){
                cout<<"YES"<<endl;return;
            }
        }
        c++;
    }
    cout<<"NO"<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}