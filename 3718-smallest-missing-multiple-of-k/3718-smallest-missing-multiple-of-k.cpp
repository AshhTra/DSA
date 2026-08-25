class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(101, 0);
        for(int i = 0; i < n; i++){
            freq[nums[i]] = 1;
        }

        int i = 1;
        while(1){
            if(i * k > 100 || freq[i * k] == 0) return i * k;
            i++;
        }
        return -1;
    }
};