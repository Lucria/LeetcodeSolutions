/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    stack<int> s;
    stack<int> minS;
    /** initialize your data structure here. */ 
    /** To do this in O(1) extra space and not use two stack, need to keep an integer
    to keep track of the minimum element and push 2 * x - minEle if x is smaller than min ele
    During pop, if y is less than the current minEle, update minEle = 2 * minEle - y to get back the previous minElement
    **/
    MinStack() {

    }
    
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minS.push(x);
        } else {
            if (x <= minS.top()) {
                minS.push(x);
            }
            s.push(x);
        }
        return;
    }
    
    void pop() {
        int t = s.top();
        if (minS.top() == t) {
            minS.pop();
        }
        s.pop();
        return;
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

