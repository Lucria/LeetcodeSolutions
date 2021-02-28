/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
class FreqStack {
public:
    FreqStack() {
    }

    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freqStack;
    int maxFreq = 0;

    void push(int x) {
        freq[x]++;
        maxFreq = max(maxFreq, freq[x]);
        freqStack[freq[x]].push(x);
    }

    int pop() {
        int temp = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        if (!freqStack[freq[temp]].size()) maxFreq--;
        freq[temp]--;
        return temp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
// @lc code=end

