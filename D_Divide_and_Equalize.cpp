
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

void add_divs(int x, map<int, int>&divs){
    int i = 2;
    while(i * i <= x){
        while (x % i == 0){
            divs[i]++;
            x /= i;
        }
        i++;
    }
    if(x > 1) divs[x]++;
}

bool solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    map<int, int> divs;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        add_divs(a[i], divs);
    }
    for(auto e: divs){
        if(e.second % n != 0) return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}