
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

int RecurSolve(int ind, vector<char> v, map<vector<char>,int>& mpp, int n, map<vector<char>,int>& dp) {
    if (ind >= n - 1) {
        return 0;
    }

    if (mpp[v] == 1) {
        return 0;
    }

    if (dp.find(v) != dp.end()) {
        return dp[v];
    }

    mpp[v] = 1;

    vector<char> leftVector = v;
    leftVector.erase(leftVector.begin() + ind);

    vector<char> rightVector = v;
    rightVector.erase(rightVector.begin() + ind + 1);

    int left = 1 + RecurSolve(ind, leftVector, mpp, n, dp);
    int right = 1 + RecurSolve(ind, rightVector, mpp, n, dp);

    dp[v] = left + right;

    return dp[v];
}


void Solve(){
    int n;cin>>n;
    vector<char>s;
    FOR(i,n){
        cin>>s[i];
    }
    map<vector<char>, int>mpp;
    map<vector<char>,int>dp;
    FOR(i,n){
        vector<char> key(n, '-'); // Creating a default key of size n filled with '-'
        key[i] = s[i]; // Assigning the actual character to its respective position
        dp[key] = -1;
    }

    int ans=RecurSolve(0,s,mpp,n,dp);
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}