/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // * Iteartively
        ListNode* prevNode = NULL;
        while (head != NULL) {
            ListNode* nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;

        // return reverseListRecursive(head);
    }

    // * Recursive
    ListNode* reverseListRecursive(ListNode* head) {
        // * Recursively
        if (head == NULL) {
            return NULL;
        }
        ListNode* newHead = head;
        if (head->next != NULL) {
            newHead = reverseListRecursive(head->next);
            head->next->next = head;
        }
        head->next = NULL;
        return newHead;
    }
};
// @lc code=end

