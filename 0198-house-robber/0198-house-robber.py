class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        
        prev1 = nums[0]
        prev2 = 0

        for i in range(2, n + 1):
            pick = nums[i - 1] + prev2
            npick = prev1
            curr = max(pick, npick)

            prev2 = prev1
            prev1 = curr

        return prev1

        