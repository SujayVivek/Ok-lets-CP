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
    // int t; cin >> t;cout<<"hi";
    // while(t--){
        string s;cin>>s; int n= s.length();
        vector<vector<int>> v(n,vector<int>(3));
        v[0] = {0, s[0],0}; // Set the first element directly
        int l=0;
        FOR(i,n){
            if(s[i-1]=='(')l++;
            else l--;

            v[i] = {l, (int)s[i],i};
        }

        sort(v.begin(),v.end(),computation);

        for(int i=0;i<n;i++){
            cout<<(char)v[i][1];
        }
        cout<<endl;
    // }

    return 0;
}
