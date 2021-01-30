/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, temp, nums);
        return ans;
    }

private:
    void backtrack(vector<vector<int>>& list, vector<int> tempList, vector<int>& nums) {
        if (tempList.size() == nums.size()) {
            vector<int> temp = tempList;
            // cout << "hit here" << endl;
            list.push_back(temp);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (find(tempList.begin(), tempList.end(), nums[i]) != tempList.end()) {
                    continue;
                } else {
                    tempList.push_back(nums[i]);
                    // cout << nums[i] << endl;
                    backtrack(list, tempList, nums);
                    tempList.pop_back();
                }
            }
        }
    }
};

// @lc code=end

