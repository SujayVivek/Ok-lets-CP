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
    int n, k; cin>>n>>k;
    string b;
    string a; cin>>a;
    bool ok = true;
    for(int i = 0; i<n-k; i++){
        if(a[i]==a[i+k]) ok &= true;
        else {ok&=false; break;}
    }
    if(ok) {
        cout<<n<<endl;
        cout<<a<<endl;return;
    }
    b=a;
    ok = true;
    for(int i = 0; i<k; i++){
        int j = i+k;
        while(j<n){
            b[j] = b[i];
            j+=k;
        }
    }
    for(int i = 0; i<n; i++){
        if(a[i]<b[i]){ok&=true; break;}
        else if(a[i]>b[i]){ok&=false; break;}
    }
    if(ok){
        cout<<n<<endl;
        for(auto v: b) cout<<v;
        cout<<endl;return;
    }
    //to see if a[k-1]==9
    if(a[k-1]=='9'){
        int j = k-1;
        while(b[j]=='9' && j>=0){
            b[j] = '0';
            j--;
        }
        if(j==-1){
            int t = -1;
            for(int i = 0; i<n ; i++){
                if(i==t+k) {b[i] = '1'; t+=k;}
                else b[i] = '0';
            }
            cout<<n+1<<endl;
            cout<<1;
            for(auto v: b)cout<<v;
            cout<<endl;return;
        }else{
            b[j] = b[j]+1;
            for(int i = j; i<k; i++){
                int t = i;
                while(t<n){
                    b[t] = b[i];
                    t+=k;
                }
            }
            cout<<n<<endl;
            for(auto v: b)cout<<v;
            cout<<endl;return;
        }
    }else{
        int j = k-1;
        // cout<<"HI";
        while(j<n){
            b[j] = b[j]+1;
            j+=k;
        }
        cout<<n<<endl;
        for(auto v: b)cout<<v;
        cout<<endl;return;
    }
    
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}