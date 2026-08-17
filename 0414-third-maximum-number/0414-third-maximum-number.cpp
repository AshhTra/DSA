class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();

        long long m1 = -1e18, m2 = -1e18, m3 = -1e18;
        for(int i = 0; i < n; i++){
            if(nums[i] > m1){
                m3 = m2;
                m2 = m1;
                m1 = nums[i];
            }else if(nums[i] > m2 && nums[i] != m1){
                m3 = m2;
                m2 = nums[i];
            }else if(nums[i] > m3 && nums[i] != m2 && nums[i] != m1){
                m3 = nums[i];
            }
        }
        if(m3 != -1e18) return m3;
        return m1;
    }
};