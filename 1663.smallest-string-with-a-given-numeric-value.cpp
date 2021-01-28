/*
 * @lc app=leetcode id=1663 lang=cpp
 *
 * [1663] Smallest String With A Given Numeric Value
 */

// @lc code=start
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        int index = n - 1;
        while(k > 0) {
            int diff = min(k, 25);
            ans[index] += diff;
            k -= diff;
            index--;
        }

        return ans;
    }
};
// @lc code=end

