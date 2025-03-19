#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
typedef tuple<char, int, char, int> XX;
void calc(int &A, int &B, int &C, int L_ans, int R_ans, int tot) {
    int temp_A = A, temp_B = B, temp_C = C;
    if(temp_B > temp_A) {
        A = temp_A + temp_B * L_ans;
        B = temp_B * (1 + R_ans);
        C = temp_B * tot + temp_C;
    } else {
        A = temp_A * (1 + L_ans);
        B = temp_B + temp_A * R_ans;
        C = temp_A * tot + temp_C;
    }
}
void Solve() {
    int n;
    cin >> n;
    vector<XX> vec(n);
    for(int i = 0; i < n; i++) {
        char L_val, R_val;
        int Aval, Bval;
        cin >> L_val >> Aval >> R_val >> Bval;
        vec[i] = make_tuple(L_val, Aval, R_val, Bval);
    }
    int A = 1, B = 1, C = 0;

    for(int idx = n - 1; idx >= 0; idx--) {
        char L_val = get<0>(vec[idx]);
        int Aval = get<1>(vec[idx]);
        char R_val = get<2>(vec[idx]);

        int Bval = get<3>(vec[idx]);
        int L_ans = (L_val == 'x') ? Aval - 1 : 0;
        int left_const = (L_val == 'x') ? 0 : Aval;
        int R_ans = (R_val == 'x') ? Bval - 1 : 0;
        int R_left = (R_val == 'x') ? 0 : Bval;
        int tot = left_const + R_left;
        calc(A, B, C, L_ans, R_ans, tot);
    }
    cout << A + B + C << endl;
}

int32_t main() {
    int _tt = 1;
    cin >> _tt;
    while(_tt--) {
        Solve();
    }
    
    return 0;
}