#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int N, M; cin>>N>>M;
    vector<vector<char>> A(N, vector<char>(N));
    vector<vector<char>> B(M, vector<char>(M));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>A[i][j];
        }
    }
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            cin>>B[i][j];
        }
    }
    for(int i = 0; i<N-M+1; i++){
        for(int j = 0; j<N-M+1; j++){
            bool ok = true;
            for(int a = 0; a<M; a++){
                for(int b = 0; b<M; b++){
                    if(A[a+i][b+j] != B[a][b]){ ok = false; break;}
                }
                if(!ok)break;
            }
            if(ok){
                cout<<i+1<<" "<<j+1<<endl; exit(0); 
            }
        }
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}