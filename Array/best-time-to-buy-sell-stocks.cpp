#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief Calculates the maximum profit that can be achieved by buying and selling a stock.
     * 
     * You are given an array prices where prices[i] is the price of a given stock on the ith day.
     * 
     * You want to maximize your profit by choosing a single day to buy one stock and choosing a 
     * different day in the future to sell that stock. Return the maximum profit you can achieve 
     * from this transaction. If you cannot achieve any profit, return 0.
     * 
     * @param prices The array of stock prices.
     * @return The maximum profit that can be achieved.
     */
    int maxProfit(vector<int>& prices) {
        int mini = 1e9;  // Initialize minimum price to a large value
        int maxProfit = 0;  // Initialize maximum profit to 0
        for (auto it : prices) {
            mini = min(mini, it);  // Update minimum price encountered so far
            maxProfit = max(maxProfit, it - mini);  // Update maximum profit
        }
        return maxProfit;
    }
};

/**
 * Approach:
 * - The problem is approached by iterating through the array of stock prices.
 * - At each iteration, the minimum price encountered so far is updated.
 * - The maximum profit that can be achieved by selling the stock on that day is calculated
 *   by subtracting the minimum price from the current price.
 * - The maximum profit encountered so far is updated if the current maximum profit is greater.
 * - Finally, the maximum profit is returned.
 *
 * Time Complexity:
 * - The time complexity is O(n), where n is the number of elements in the prices array.
 * - This is because we iterate through the array once to find the maximum profit.
 *
 * Space Complexity:
 * - The space complexity is O(1) because we use only a few additional variables.
 */

int main() {
    Solution solution;

    // Example
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int max_profit = solution.maxProfit(prices);
    cout << "Maximum profit: " << max_profit << endl;

    return 0;
}
