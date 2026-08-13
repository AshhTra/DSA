class Solution:
    def f(self, i, nums, dp) -> int:
        if i == 0: 
            return nums[0]
        if i < 0:
            return 0
        if dp[i] != -1:
            return dp[i]
        
        pick = nums[i] + self.f(i - 2, nums, dp)
        npick = self.f(i - 1, nums, dp)

        dp[i] = max(pick, npick)
        return dp[i]

    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * n
        return self.f(n - 1, nums, dp)

        