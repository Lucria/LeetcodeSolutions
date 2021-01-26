/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        int test = right - k + 1;
        int kth;
        while (true) {
            int index = partition(nums, left, right);
            if (index == test) {
                kth = nums[index];
                break;
            }
            if (index < test) {
                left = index + 1;
            } else {
                right = index - 1;
            }
        }
        return kth;
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], storeIndex = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < pivot) {
                storeIndex++;
                swap(nums[i], nums[storeIndex]);
            }
        }
        swap(nums[left], nums[storeIndex]);
        return storeIndex;
    }
};
// @lc code=end

