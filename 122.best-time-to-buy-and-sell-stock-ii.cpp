/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int length = prices.size();
        for (int i = 0; i < length - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                profit += (prices[i+1] - prices[i]);
            }
        }
        return profit;
    }
};
// @lc code=end

