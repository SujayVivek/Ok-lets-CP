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
    int n; cin>>n;
    int S = 0, c = 0; int Se = 0, So = 0;
    while(n){
        int a = n%10;
        if(c%2==0){
            Se+= a;
        }else{
            So+= a;
        }
        S+= a, n/=10;
        c++;
    }
    if(abs(Se-So)%11==0 && S%3==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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