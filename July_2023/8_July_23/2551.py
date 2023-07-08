class Solution:
    def putMarbles(self, W: List[int], k: int) -> int:
        n = len(W)
        pairs = [0] * (n - 1)
        for i in range(1, n):
            pairs[i - 1] = W[i] + W[i - 1]
        pairs.sort()
        
        min_sum = 0
        max_sum = 0
        for i in range(k - 1):
            min_sum += pairs[i]
            max_sum += pairs[n - i - 2]
        
        return max_sum - min_sum