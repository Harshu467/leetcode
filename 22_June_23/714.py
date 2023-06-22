# Intuition
# The intuition behind the solution is to keep track of the minimum cost to buy a stock at each day and the maximum profit that can be achieved by selling the stock at each day.

# Approach:
# Initialize two variables: buy and sell. Set buy to negative infinity and sell to zero. These variables will keep track of the maximum profit at each day.

# Iterate through the prices of the stocks starting from the first day.

# Update the buy variable by taking the maximum of its current value and the previous sell value minus the stock price. This represents the maximum profit after buying the stock.
# buy = max(buy, sell - price)

# Update the sell variable by taking the maximum of its current value and the previous buy value plus the stock price minus the transaction fee. This represents the maximum profit after selling the stock.
# sell = max(sell, buy + price - fee)

# After iterating through all the prices, the maximum profit will be stored in the sell variable.

# Return the value of sell as the maximum profit.

# Complexity
# Time complexity:
# O(n)

# Space complexity:
# O(1)
class Solution:

    def maxProfit(self, prices: List[int], fee: int) -> int:
        buy = float('-inf')
        sell = 0

        for price in prices:
            buy = max(buy, sell - price)
            sell = max(sell, buy + price - fee)

        return sell