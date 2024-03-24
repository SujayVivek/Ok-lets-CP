
//   _______ _     _                     _        _        __             _   _            _                            
//  |__   __| |   (_)                   | |      (_)      / _|           | | | |          (_)                           
//     | |  | |__  _ ___    ___ ___   __| | ___   _ ___  | |_ ___  _ __  | |_| |__   ___   _ _ __  ___  __ _ _ __   ___ 
//     | |  | '_ \| / __|  / __/ _ \ / _` |/ _ \ | / __| |  _/ _ \| '__| | __| '_ \ / _ \ | | '_ \/ __|/ _` | '_ \ / _ \
//     | |  | | | | \__ \ | |_| (_) | |_| |  __/ | \__ \ | || (_) | |    | |_| | | |  __/ | | | | \__ \ |_| | | | |  __/
//     |_|  |_| |_|_|___/  \___\___/ \__,_|\___| |_|___/ |_| \___/|_|     \__|_| |_|\___| |_|_| |_|___/\__,_|_| |_|\___|
                                                                                                                     
#include <bits/stdc++.h>
using namespace std;                                                                                                                     
#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back
#define ll long long

vector<int> Solve(vi &nums, int target){
    unordered_map <int,int> numMap;
    FOR(i,nums.size()){
        int compliment = target- nums[i];
        if(numMap.find(compliment)!=numMap.end()){
            return {i, numMap[compliment]};
        }
        numMap[nums[i]]=i;
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        int target;cin>>target;
        int n;cin>>n;
        vi nums(n,-1);
        FOR(i,n){
            cin>>nums[i];
        }
        vi ans= Solve(nums, target);
        for(auto it: ans){
            cout<<it<<" ";
        }
    }
    return 0;
}