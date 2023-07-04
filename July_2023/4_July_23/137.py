from collections import Counter

class Solution:
    def singleNumber(self, nums):
        count = Counter(nums)
        for num, freq in count.items():
            if freq == 1:
                return num
