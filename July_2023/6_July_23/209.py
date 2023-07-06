class Solution:
    def minSubArrayLen(self, target: int, A: List[int]) -> int:
        i = 0
        j = 0
        sum = 0
        ans = 1000000
        
        while j < len(A):
            sum += A[j]
            
            while sum >= target:
                ans = min(ans, j - i + 1)
                sum -= A[i]
                i += 1
            
            j += 1
        
        return 0 if ans == 1000000 else ans