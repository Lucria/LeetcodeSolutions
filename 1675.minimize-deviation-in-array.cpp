/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

// @lc code=start
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int difference = INT_MAX;
        int smallest = INT_MAX;
        priority_queue<int> pq;
        for (auto i: nums) {
            i = i % 2 ? i * 2 : i;
            pq.push(i);
            smallest = min(smallest, i);
        }

        while (pq.top() % 2 == 0) {
            int top = pq.top();
            pq.pop();
            difference = min(difference, top - smallest);
            smallest = min(smallest, top / 2);
            pq.push(top / 2);
        }
        return min(difference, pq.top() - smallest);
    }
};
// @lc code=end

