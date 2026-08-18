class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(51, 0);

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> unique_elements(nums.begin() + i, nums.begin() + i + k);
            for (int x : unique_elements) {
                count[x]++;
            }
        }

        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) return x;
        }
        return -1;
    }
};