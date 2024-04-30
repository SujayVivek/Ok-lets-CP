#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;long long k;
        cin>>n>>k;

        vector <long long> a(n);
        long long total_cards = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            total_cards+=a[i];
        }
         long long max_score = min(total_cards, k+n);

         long long needed_cards= 0;

         for (int i=1;i<=n;++i){
            if(i<=n/2){
                needed_cards+= a[i-1];
            }
            if(i+n-1<=n){
                needed_cards-=a[i+n-2];
            }
            if(needed_cards <=k){
                long long remaining = k-needed_cards;
                long long extra = min(a[i-1],remaining);
                max_score = max(max_score, n-extra);
            }
         }
         cout<<max_score<<endl;
    }
    return 0;
}