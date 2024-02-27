
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
#define PB push_back

int main(){
    int t;
    cin>>t;
    while(t--){
        
    long long a, b, l;
    cin >> a >> b >> l;

    set<long long> possible_k_values;

    
    for (long long x = 0; pow(a, x) <= l; x++) {
        for (long long y = 0; pow(b, y) <= l; y++) {
            long long k = l / (pow(a, x) * pow(b, y));
            if(k==1)possible_k_values.insert(1);
            if (k * pow(a, x) * pow(b, y) == l) {
                
                possible_k_values.insert(k);
            }
        }
    }

    
    cout << possible_k_values.size() << endl;
    }


    return 0;
}