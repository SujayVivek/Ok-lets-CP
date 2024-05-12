
//   _______ _     _                     _        _        __             _   _            _                            
//  |__   __| |   (_)                   | |      (_)      / _|           | | | |          (_)                           
//     | |  | |__  _ ___    ___ ___   __| | ___   _ ___  | |_ ___  _ __  | |_| |__   ___   _ _ __  ___  __ _ _ __   ___ 
//     | |  | '_ \| / __|  / __/ _ \ / _` |/ _ \ | / __| |  _/ _ \| '__| | __| '_ \ / _ \ | | '_ \/ __|/ _` | '_ \ / _ \
//     | |  | | | | \__ \ | |_| (_) | |_| |  __/ | \__ \ | || (_) | |    | |_| | | |  __/ | | | | \__ \ |_| | | | |  __/
//     |_|  |_| |_|_|___/  \___\___/ \__,_|\___| |_|___/ |_| \___/|_|     \__|_| |_|\___| |_|_| |_|___/\__,_|_| |_|\___|
                                                                                                                     
#include <bits/stdc++.h>
using namespace std;                                                                                                                     
#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back
#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, priority_queue<int>> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]>>2].push(-a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        cout << -mp[a[i]>>2].top() << " ";
        mp[a[i]>>2].pop();
    }
    cout << endl;
}
 
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}