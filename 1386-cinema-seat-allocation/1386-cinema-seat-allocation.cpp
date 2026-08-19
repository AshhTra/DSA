class Solution {
    bool f(int row, int col, unordered_map<int, unordered_set<int>>& seat){
        if(seat[row].find(col) != seat[row].end() || 
            seat[row].find(col + 1) != seat[row].end() || 
            seat[row].find(col + 2) != seat[row].end() || 
            seat[row].find(col + 3) != seat[row].end()){
                return false;
            }
        return true;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>>seat;
        for(auto it : reservedSeats){
            if(it[1] == 1 || it[1] == 10) continue;
            seat[it[0]].insert(it[1]);
        }

        long long ans = 2LL * n;
        for (auto& [row, seats] : seat) {
            ans -= 2;

            if (f(row, 2, seat) ||
                     f(row, 4, seat) ||
                     f(row, 6, seat)) {
                ans += 1;
            }
        }
        return ans;
    }
};