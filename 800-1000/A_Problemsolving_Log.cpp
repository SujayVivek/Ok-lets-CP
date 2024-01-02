#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>hash(26,0);
        for(int i=0;i<n;i++){
            char ch;cin>>ch;
            hash[ch-65]++;

        }int ctr=0;
        for(int i=0;i<26;i++){
            if(hash[i]>=i+1){
                ctr++;
            }
        }
        cout<<ctr<<endl;
    }
    return 0;
}