#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define endl "\n"
#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

void Solve() {
    int n;cin>>n;
    vi a(n+2,0);
    for(int i = 1; i<= n; i++){
        cin>>a[i];
    }
    int negNum = 0, posNum = 0;
    int ans = 0, ansL = 0, ansR = 0;
    for(int i = 0; i<n; i++){
        if(a[i]>0) posNum++;
        else if(a[i]<0) negNum++;

        if(a[i]==0){
            if(posNum+negNum){
                int Size = posNum + negNum;
                int prod = 1, prod1 = 1, prod2 = 1; bool ok1 = false, ok2 = false; int numN  =0, pos1 = 0, pos2 = 0;
                for(int j = i-Size; j<i; j++){
                    if(a[j]<0) numN++;

                    if(a[j]<0 && !ok1){ok1 = true; pos1 = j;}
                    if(a[i-j]<0 && !ok2){ok2 = true; pos2 = i-j;}
                    if(ok1){prod1*=a[j];}
                    if(ok2){prod2*=a[j];}
                    prod*=a[j];
                }
                if(numN%2==0){
                    ans = prod;
                    ansL = i-Size;
                    ansR = i;
                }else{
                    if(prod1>ans){
                        ans = prod1;
                        ansL = i-Size+pos1;
                        ansR = n-i-1;
                    }
                    if(prod2>ans){
                        ans = prod2; 
                        ansL = i-Size;
                        ansR = n-i + Size-pos2;
                    }
                }
                posNum = 0, negNum = 0;
            }
        }
    }
    cout<<ansL<<" "<<ansR<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}