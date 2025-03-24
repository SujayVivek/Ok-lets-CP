#include <bits/stdc++.h>
using namespace std;

vector<int> getNextSeat(int a, int b, int occupied) {
    vector<int> table(6);
    table[0] = a;
    table[1] = b;
    table[2] = occupied;
    
    if(occupied == 0) {
        table[3] = 3*a + 1;       
        table[4] = 3*b + 1;        
        table[5] = 3*(a+b) + 2;    
    } else if(occupied == 1) {
        table[3] = 3*a + 1;
        table[4] = 3*b + 2;
        table[5] = 3*(a+b) + 3;
    } else if(occupied == 2) {
        table[3] = 3*a + 2;
        table[4] = 3*b + 1;
        table[5] = 3*(a+b) + 3;
    } else {
        table[3] = 3*a + 2;
        table[4] = 3*b + 2;
        table[5] = 3*(a+b) + 6;
    }
    return table;
}
void Solve(){
    int n;
    cin >> n;
        
        vector<int> guestType(n);
        for(int i = 0; i < n; i++) {
            cin >> guestType[i];
        }
        vector<vector<int>> emptyTables;
        for(int sum = 0; emptyTables.size() < n; sum++) {
            for(int a = 0; a <= sum && emptyTables.size() < n; a++) {
                int b = sum - a;
                emptyTables.push_back(getNextSeat(a, b, 0));
            }
        }
        sort(emptyTables.begin(), emptyTables.end(), [](const vector<int> &t1, const vector<int> &t2) {
            if(t1[5] != t2[5]) return t1[5] < t2[5];
            if(t1[3] != t2[3]) return t1[3] < t2[3];
            return t1[4] < t2[4];
        });
        
        int emptyIndex = 0;
        auto compareTable = [](const vector<int> &t1, const vector<int> &t2) {
            if(t1[5] != t2[5]) return t1[5] > t2[5];
            if(t1[3] != t2[3]) return t1[3] > t2[3];
            return t1[4] > t2[4];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compareTable)> partialTables(compareTable);
        vector<pair<int,int>> results(n);
        
        for(int i = 0; i < n; i++) {
            if(guestType[i] == 0) {
                vector<int> table = emptyTables[emptyIndex++];
                results[i] = {table[3], table[4]};
                partialTables.push(getNextSeat(table[0], table[1], 1));
            } else {
                vector<int> tableToUse;
                bool useEmptyTable = false;
                
                if(emptyIndex < emptyTables.size() && !partialTables.empty()) {
                    vector<int> emptyOption = emptyTables[emptyIndex];
                    vector<int> partialOption = partialTables.top();
                    
                    if(emptyOption[5] < partialOption[5] || 
                       (emptyOption[5] == partialOption[5] && 
                        (emptyOption[3] < partialOption[3] || 
                         (emptyOption[3] == partialOption[3] && emptyOption[4] < partialOption[4])))) {
                        useEmptyTable = true;
                    }
                } else {
                    useEmptyTable = emptyIndex < emptyTables.size();
                }
                
                if(useEmptyTable) {
                    vector<int> table = emptyTables[emptyIndex++];
                    results[i] = {table[3], table[4]};
                    partialTables.push(getNextSeat(table[0], table[1], 1));
                } else {
                    vector<int> table = partialTables.top();
                    partialTables.pop();
                    results[i] = {table[3], table[4]};
                    
                    if(table[2] < 3) {
                        partialTables.push(getNextSeat(table[0], table[1], table[2] + 1));
                    }
                }
            }
        }
        
        for(auto &p : results) {
            cout << p.first << " " << p.second << "\n";
        }
}
int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}