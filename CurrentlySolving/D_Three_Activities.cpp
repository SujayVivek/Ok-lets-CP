#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        map<int,int>A(n,0);
        map<int,int>B(n,0);
        map<int,int>C(n,0);
        for(int i=0;i<n;i++){
            int ch;
            cin>>ch;
            A.insert({ch,i+1});
        }
        for(int i=0;i<n;i++){
            int ch;
            cin>>ch;
            B.insert({ch,i+1});
        }
        for(int i=0;i<n;i++){
            int ch;
            cin>>ch;
            C.insert({ch,i+1});
        }int sum=0;int p=0,j=0,k=0,l=1;
        

    }
    return 0;
}