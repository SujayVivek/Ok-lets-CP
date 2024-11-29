#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
int points = 0;
int calc(int r, int x, int y, int points){
    if(x>=r){
        return points;
    }
    while(x*x + y*y>= r*r){
        y--;
    }
    
    return calc(r, x+1, y, points + y);
}
void Solve() {
    int r; cin>>r;
    int p = calc(r+1, 1, r, 0);
    int q = calc(r, 1, r-1, 0);
    cout<< 4*(p-q+1)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}