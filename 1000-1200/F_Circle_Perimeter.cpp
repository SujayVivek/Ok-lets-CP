
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
    long long r;
    cin >> r;
    long long height = r;
    long long ans = 0;
    for(long long i = 0; i <= r; i++)
    {
        while(i*i+height*height >= (r+1)*(r+1))
        {
            height--;
        }
        long long in_height = height;
        while(i*i+in_height*in_height >= r*r && in_height > 0)
        {
            in_height--;
            ans++;
        }
    }
    cout << ans*4 << endl;
}
 
int main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}