/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> answer;
        permutate(answer, S, 0);
        return answer;
    }

private:
    void permutate(vector<string>& ans, string& s, int i) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        permutate(ans, s, i + 1);
        if (isalpha(s[i])) {
            if (islower(s[i])) {
                s[i] = toupper(s[i]);
            } else {
                s[i] = tolower(s[i]);
            }
            permutate(ans, s, i + 1);
        }
    }
};
// @lc code=end

