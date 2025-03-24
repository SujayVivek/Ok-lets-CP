#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool isPrime(int x) {
    if(x < 2) return false;
    for (int i = 2; i*i<= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}
int nextPrime(int x) {
    while (!isPrime(x)) x++;
    return x;
}
int minSum(int r) {
    return r * (r + 1) / 2;
}

void Solve() {
    int n; 
    cin >> n;
    if(n <= 3){
        if(n == 2) {cout <<"2 1"<< endl;return;}
        if(n == 3) {cout <<"2 1 3"<< endl;return;}
    }
    int L = n/3, Q = nextPrime((L+1)/2), T_prime = Q*L-1, min_sum = minSum(L);
    vector<bool> used(n+1, false);
    vi block;
    int r = L, rem = T_prime; int x;
    for ( x = n; x >= 1 && r > 0; x--) {
        if(x <= rem-minSum(r - 1)) {
            block.push_back(x); used[x] = true;
            rem -= x; r--;
        }
    }
    sort(block.begin(), block.end(), greater<int>()); vi remNumbers;
    for (int x = 1; x <= n; x++){
        if(!used[x]) remNumbers.push_back(x);
    }
    sort(remNumbers.begin(), remNumbers.end());
    for (int x:block) cout <<x<<" ";
    for (int x:remNumbers) cout <<x<<" ";
    cout<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
