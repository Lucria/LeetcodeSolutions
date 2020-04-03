/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        // Uses XOR swap
        int length = s.size();
        for (int i = 0; i < length / 2; i++) {
            s[i] = s[i] ^ s[length - i -1];
            s[length - i - 1] = s[i] ^ s[length - i -1];
            s[i] = s[i] ^ s[length - i -1];
        }
    }
};
// @lc code=end

