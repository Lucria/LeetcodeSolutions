/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Reverse first half
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* temp = slow;
            slow = slow->next;
            temp->next = prev;
            prev = temp;
        }
        if (fast) {
            slow = slow->next;
        }

        while (prev && prev->val == slow->val) {
            slow = slow->next;
            prev = prev->next;
        }
        return (!prev);
    }
};
// @lc code=end

