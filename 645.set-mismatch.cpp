/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> answers;
        unordered_map<int, int> counts;
        int first = 0;
        int second = 0;
        for (int i = 0; i < n; i++) {
            counts[nums[i]] += 1;
        }
        for (int i = 0; i < n; i++) {
            if (!counts[i + 1]) {
                second = i + 1;
            }
            if (counts[i + 1] == 2) {
                first = i + 1;
            }
        }
        answers.push_back(first);
        answers.push_back(second);
        return answers;
    }
};
// @lc code=end

