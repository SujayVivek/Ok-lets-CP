#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int Solve() {
    int K; cin>>K;
    string S, T; cin>>S>>T;
    if(S.length()<T.length()){
        if((T.length()-S.length())>1)return 0;
        int i = 0, j = 0, buffer = 1;
        while(i<S.length() && j<T.length()){
            if(S[i]==T[j]){i++; j++;}
            else{
                if(buffer){j++; buffer = 0;}
                else return 0;
            }
        }
        return 1;
    }
    else if((S.length() == T.length())){
        int buffer = 1;
        for(int i = 0; i<S.length(); i++){
            if(S[i]!=T[i] && buffer){
                buffer = 0;
            }else if(S[i]!=T[i] && !buffer){
                return 0;
            }
        }
        return 1;
    }else{
        int i = 0, j = 0;
        int buffer = 1;
        if(S.length()-T.length()>1)return 0;
        while(i<S.length() && j<T.length()){
            if(S[i]==T[j]){i++; j++;}
            else{
                if(buffer){i++; buffer = 0;}
                else return 0;
            }
        }
        return 1;
    }
}

void Psolve(){
    if(Solve()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Psolve();
    }
    return 0;
}