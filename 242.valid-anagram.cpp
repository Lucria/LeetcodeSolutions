/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        // ! Peresonal solution
        // map<char, int> sTable;
        // map<char, int> tTable;
        // for (auto& it: s) {
        //     sTable[it]++;
        // }
        // for (auto & it: t) {
        //     tTable[it]++;
        // }
        // return sTable == tTable;
        // * Better solution
        // * Use one unordered map only and compare length first
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count: counts) {
            if (count.second) return false;
        }
        return true;
    }
};
// @lc code=end

