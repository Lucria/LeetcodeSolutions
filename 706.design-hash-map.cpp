/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
    vector<list<pair<int ,int>>> data;
    int size = 10000;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data.resize(size);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &list = data[key % size];
        for (auto& val : list) {
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &list = data[key % size];
        if (list.empty()) {
            return -1;
        }
        for (auto & val : list) {
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &list = data[key % size];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {
                it = list.erase(it);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

