class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0

        dp = [1] * n 
        max_length = 1  
        result = 0 

        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1

            max_length = max(max_length, dp[i])

        for i in range(n):
            if dp[i] == max_length:
                result += 1

        return result