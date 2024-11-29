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
    vi a(n+m+1, 0), b(n+m+1, 0);
    for(auto &x: a) cin>>x;
    for(auto &x: b) cin>>x;
    int c = 0, d = 0;
    int nF = -1, mF = -1;
    int Sum = 0;
    for(int i = 0; i<n+m; i++){
        if((a[i]>b[i] && c<n) || d>=m){
            Sum += a[i]; 
        }else{
            Sum += b[i];
        }

        if(a[i]>b[i]){
            c++;
            if(c==n+1) nF = i; 
        }else{
            d++;
            if(d==m+1) mF = i;
        }
    }
    if(a[n+m]>b[n+m]){
        c++;
        if(c==n+1) nF = n+m;
    }else{
        d++;
        if(d==m+1) mF = n+m;
    }
    c = 0, d = 0;
    int lastAns = Sum;
    
    for(int i = 0; i<n+m; i++){
        Sum = lastAns;
        if((a[i]>b[i] && c<n) || d>=m){
            if(i<nF){
                Sum-=a[i];
                Sum = Sum + a[nF] - b[nF];
                Sum += b[n+m];
            }
            else{
                Sum-=a[i];
                Sum+= a[n+m];
            }
            c++;
        }else{
            if(i<mF){
                Sum-=b[i];
                Sum = Sum + b[mF] - a[mF];
                Sum += a[n+m];
            }else{
                Sum-=b[i];
                Sum+=b[m+n];
            }
            d++;
        }
        cout<<Sum<<" ";
    }
    cout<<lastAns<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}