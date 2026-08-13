class Solution:
    def f(self, i, nums, dp) -> int:
        if i == 0:
            return nums[0]
        if i < 0:
            return 0
        if dp[i] != -1:
            return dp[i]
        
        p = nums[i] + self.f(i - 2, nums, dp)
        np = self.f(i - 1, nums, dp)

        dp[i] = max(p, np)
        return dp[i]
        
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        a1 = nums[:-1]
        a2 = nums[1:]

        dp1 = [-1] * len(a1)
        dp2 = [-1] * len(a2)

        return max(self.f(len(a1) - 1, a1, dp1), self.f(len(a2) - 1, a2, dp2))