class Solution:   
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        a1 = nums[:-1]
        p1 = a1[0]
        p2 = 0
        c1 = a1[0]
        for i in range(2, len(a1) + 1):
            c1 = max(a1[i - 1] + p2, p1)
            p2 = p1
            p1 = c1

        a2 = nums[1:]
        p1 = a2[0]
        p2 = 0
        c2 = a2[0]
        for i in range(2, len(a2) + 1):
            c2 = max(a2[i - 1] + p2, p1)
            p2 = p1
            p1 = c2


        return max(c1, c2)