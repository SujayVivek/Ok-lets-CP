#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve()
{
    int n, x;
    cin >> n >> x;
    int Re_n = 0;
    if(x>n){
        cout<<-1<<endl;return;
    }
    bool ok1 = true, ok2 = true;
    for(int i = 62; i>=0; i--){
        int a = (n >> i) & 1; 
        int b = (x >> i) & 1; 
        if(a==1 && b==0 && ok1){
            Re_n+= (1LL<<i);
            ok1 = false;
        }else if(a==1 && b==0 && !ok1){
            Re_n-= (1LL<<i);
        }else if(b==1 && a==0){
            ok2 = false; break;
        }else if(a == 1 && b== 1 && !ok1){
            ok2 = false; break;
        }
    }
    if(!ok2){
        cout<<-1<<endl;return;
    }
    if((n&(n+Re_n)) == x){
        cout<<(n+Re_n)<<endl;
    }else{
        cout<<-1<<endl;
    }
}

int32_t main()
{
    int tt_;
    cin >> tt_;
    while (tt_--)
    {
        Solve();
    }
    return 0;
}
