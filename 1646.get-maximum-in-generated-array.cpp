/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 */

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) return n;
        vector<int> arr;
        arr.push_back(0);
        arr.push_back(1);
        int result = 1;
        for (int i = 2; i <= n; i++) {
            int num = (i % 2 == 0)
                ? arr[i/2]
                : arr[(i - 1) / 2] + arr[(i - 1) / 2 + 1];
            result = max(result, num);
            arr.push_back(num);
        }
        return result;
    }
};
// @lc code=end

