/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        // ! Bad personal solution! Takes up too much time and space
        // unordered_map<char, int> hashtable;
        // for (auto& it: s) {
        //     hashtable[it]++;
        // }
        // vector<int> possibleAnswers;
        // for (auto& it: hashtable) {
        //     if (it.second == 1) {
        //         possibleAnswers.push_back(s.find(it.first));
        //     }
        // }
        // sort(possibleAnswers.begin(), possibleAnswers.end());
        // if (possibleAnswers.size() > 0) {
        //     return possibleAnswers[0];
        // }
        // return -1;
        // * Use hashtable. Store char with index and count
        unordered_map<char, pair<int, int>> t;
        int index = s.size();
        for (int i = 0; i < index; i++) {
            t[s[i]].first++;
            t[s[i]].second = i;
        }
        for (auto &it: t) {
            if (it.second.first == 1) {
                index = min(index, it.second.second);
            }
        }
        return index == s.size() ? -1 : index;
    }
};
// @lc code=end

