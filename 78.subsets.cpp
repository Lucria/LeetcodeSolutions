/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> temp;
        backtrack(answer, 0, temp, nums);
        return answer;
    }

private:
    void backtrack(vector<vector<int>>& answer, int start, vector<int> temp, vector<int>& nums) {
        answer.push_back(temp);

        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(answer, i + 1, temp, nums);
            temp.pop_back();
        }
    }
};
// @lc code=end

