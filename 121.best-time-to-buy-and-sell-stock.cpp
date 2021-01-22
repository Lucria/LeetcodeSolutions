/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) {
            return 0;
        }

        int maxProfit = 0;
        int minPrice = prices[0];

        for (int i = 1; i < len; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            } else {
                minPrice = min(minPrice, prices[i]);
            }
        }
        return maxProfit;
    }
};
// @lc code=end

