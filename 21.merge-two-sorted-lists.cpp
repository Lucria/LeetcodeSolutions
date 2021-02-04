/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        ListNode* headNode = NULL;
        if (l1->val < l2->val) {
            headNode = l1;
            l1 = l1->next;
        } else {
            headNode = l2;
            l2 = l2->next;
        }
        ListNode* currentNode = headNode;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                currentNode->next = l1;
                l1 = l1->next;
            } else {
                currentNode->next = l2;
                l2 = l2->next;
            }
            currentNode = currentNode->next;
        }

        if (l1) {
            currentNode->next = l1;
        }
        if (l2) {
            currentNode->next = l2;
        }
        return headNode;
    }
};
// @lc code=end

