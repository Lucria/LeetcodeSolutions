/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> temp;
        vector<vector<string>> anagrams;
        for (string i : strs) {
            string tempString = i;
            sort(tempString.begin(), tempString.end());
            temp[tempString].push_back(i);
        }
        for (auto i : temp) {
            anagrams.push_back(i.second);
        }
        return anagrams;
    }
};
// @lc code=end

