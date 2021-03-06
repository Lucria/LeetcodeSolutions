/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */

// @lc code=start
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for (auto i : s) {
            for (int j = 1; j < i.size(); j++) {
                s.erase(i.substr(j));
            }
        }
        int result = 0;
        for (auto i : s) {
            result += i.size() + 1;
        }
        return result;
    }
};
// @lc code=end

