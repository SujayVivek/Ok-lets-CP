
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

bool isValid(string s) {
        unordered_map <char,int> numMap(3);
        numMap['(']=0;
        numMap['[']=0;
        numMap['{']=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                numMap['(']++;
                if(numMap['(']<0){
                    return false;
                }
            }
            else if(s[i]=='{'){
                numMap['{']++;
                if(numMap['{']<0){
                    return false;
                }
            }
            else if(s[i]=='['){
                numMap['[']++;
                if(numMap['[']<0){
                    return false;
                }
            }
            if(s[i]==')'){
                numMap['(']--;
                if(numMap['(']<0){
                    return false;
                }
            }
            if(s[i]=='}'){
                numMap['{']--;
                if(numMap['{']<0){
                    return false;
                }
            }
            if(s[i]==']'){
                numMap['[']--;
                if(numMap['[']<0){
                    return false;
                }
            }
        }
        if(numMap['(']==0 && numMap['{']==0 && numMap['[']==0){
            return true;
        }
        else{
            return false;
        }
    }

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        cout<<isValid(s)<<endl;
    }
    return 0;
}