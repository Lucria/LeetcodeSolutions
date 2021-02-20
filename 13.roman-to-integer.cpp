/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        int greatest = 0;

        unordered_map<char, int> hmap;
        hmap.insert({'I', 1});
        hmap.insert({'V', 5});
        hmap.insert({'X', 10});
        hmap.insert({'L', 50});
        hmap.insert({'C', 100});
        hmap.insert({'D', 500});
        hmap.insert({'M', 1000});

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            int val = hmap[c];
            if (val >= greatest) {
                greatest = val;
                cout << greatest << endl;
                answer += val;
                continue;
            }
            answer -= val;
        }
        return answer;
    }
};
// @lc code=end

