class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> seat;
        for (auto it : reservedSeats) {
            if (it[1] == 1 || it[1] == 10) continue;
            seat[it[0]].push_back(it[1]);
        }

        long long ans = 2LL * n;
        for (auto& [row, seats] : seat) {
            ans -= 2;

            bool left = true;    // 2,3,4,5
            bool middle = true;  // 4,5,6,7
            bool right = true;   // 6,7,8,9

            for (int col : seats) {
                if (col >= 2 && col <= 5) left = false;
                if (col >= 4 && col <= 7) middle = false;
                if (col >= 6 && col <= 9) right = false;
            }

            if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};