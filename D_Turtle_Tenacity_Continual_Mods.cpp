#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& perm) {
    int result = perm[0];
    for (int i = 1; i < perm.size(); i++) {
        result %= perm[i];
        if (result == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;cin>>t;
    while(t--){
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    do {
        if (check(arr)) {
            cout << "YES" << endl;
            return 0;
        }
    } while (next_permutation(arr.begin(), arr.end()));

    cout << "NO" << endl;
    }
    

    return 0;
}
