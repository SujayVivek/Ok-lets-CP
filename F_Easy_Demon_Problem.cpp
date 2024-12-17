#include <bits/stdc++.h>
using namespace std;

 
#define int long long
#define double long double
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define vi vector<int>
#define vpii vector<pii>


const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int INF = (int)2e18 + 123;
 
int a[N] , b[N];
 
void solve()
{
    int n , m , q;
    cin >> n >> m >> q;
    set<int> c , d;
    int sa = 0 , sb = 0;
    for(int i = 0; i < n; i++)  cin >> a[i] , sa += a[i];
 
 
    for(int i = 0; i < m; i++)  cin >> b[i] , sb += b[i];
 
 
    for(int i = 0; i < n; i++){
        c.insert(sa - a[i]);
    }
    for(int i = 0; i < m; i++){
        d.insert(sb - b[i]);
    }
    while(q--){
        int x;
        cin >> x;
        bool neg = 0;
        if(x < 0)
            neg = 1;
        x = abs(x);
        bool ok = 0;
        for(int i = 1; i * i <= x; i++){
            if(x % i)   continue;
            if(!neg){
                if((c.count(i) && d.count(x / i)) || (c.count(x / i) && d.count(i))){
                    ok = 1;
                    break;
                }
                if((c.count(-i) && d.count(-x / i)) || (c.count(-x / i) && d.count(-i))){
                    ok = 1;
                    break;
                }
            }else{
                if((c.count(-i) && d.count(x / i)) || (c.count(x / i) && d.count(-i))){
                    ok = 1;
                    break;
                }
                if((c.count(i) && d.count(-x / i)) || (c.count(-x / i) && d.count(i))){
                    ok = 1;
                    break;
                }
            }
 
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
 
 
signed main(){
    _FastIO;
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    //system("pause");
}