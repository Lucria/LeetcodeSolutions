/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        vector<string> s;

        string temp;
        stringstream check1(path);
        while (getline(check1, temp, '/')) {
            if (temp == "" || temp == ".") continue;
            if (temp == "..") {
                if (!s.empty()) s.pop_back();
            } else {
                s.push_back(temp);
            }
        }

        for (auto i: s) {
            ans += "/" + i;
        }

        return ans.empty() ? "/" : ans;
    }
};
// @lc code=end

