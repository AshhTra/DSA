class Solution:   
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        a1 = nums[:-1]
        dp1 = [0] * (len(a1) + 1)
        dp1[1] = a1[0]
        for i in range(2, len(a1) + 1):
            dp1[i] = max(a1[i - 1] + dp1[i - 2], dp1[i - 1])

        a2 = nums[1:]
        dp2 = [0] * (len(a2) + 1)
        dp2[1] = a2[0]
        for i in range(2, len(a2) + 1):
            dp2[i] = max(a2[i - 1] + dp2[i - 2], dp2[i - 1])


        return max(dp1[len(a1)], dp2[len(a2)])