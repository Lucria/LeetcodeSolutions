/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        int left = 1;
        int right = 1;
        for (int i = 0; i < nums.size(); i++) {
            answer[i] *= left;
            left *= nums[i];
            answer[nums.size() - 1 -i] *= right;
            right *= nums[nums.size() - 1 -i];
        }
        return answer;
    }
};
// @lc code=end

