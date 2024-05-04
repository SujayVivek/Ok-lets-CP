#include <bits/stdc++.h>
using namespace std;

#define FOR(a,c)   for ( int (a)=1; (a)<(c); (a)++)
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back
#define ll long long

bool computation(const vector<int> &a, const vector<int>& b){
    if(a[0]==b[0]){
        return b[2]<a[2];
    }
    else{
        return a[0]<b[0];
    }
}


int main(){
    int n;cin>>n;
    vi v(n,0);
    FOR(i,n){
        cin>>v[i];
    }
    

    return 0;
}
