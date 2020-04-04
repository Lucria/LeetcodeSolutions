/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int counter1 = 0;
        int counter2 = 0;

        while ((counter1 < m) && (counter2 < n)) {
            if (nums1[counter1] < nums2[counter2]) {
                temp.push_back(nums1[counter1]);
                counter1++;
            } else if (nums2[counter2] <= nums1[counter1]) {
                temp.push_back(nums2[counter2]);
                counter2++;
            }
        }

        while (counter1 < m) {
            temp.push_back(nums1[counter1]);
            counter1++;
        }

        while (counter2 < n) {
            temp.push_back(nums2[counter2]);
            counter2++;
        }
        nums1 = temp;
    }
};
// @lc code=end

