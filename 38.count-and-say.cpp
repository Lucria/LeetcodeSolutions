/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";

        string result = "1";
        for (int i = 0; i < n - 1; i++) {
            string temp = "";
            for (int j = 0; j < result.size(); j++) {
                int count = 1;
                while ((j + 1 < result.size()) && (result[j] == result[j + 1])) {
                    count++;
                    j++;
                }
                temp += to_string(count) + result[j];
            }
            result = temp;
        }

        return result;
    }
};
// @lc code=end

