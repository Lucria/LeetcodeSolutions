/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* newHead;
        Node* l1 = head;
        Node* l2 = NULL;

        while (l1 != NULL) {
            l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l1->next->next;
        }

        l1 = head;
        while (l1 != NULL) {
            if (l1->random != NULL) l1->next->random = l1->random->next;
            l1 = l1->next->next;
        }

        l1 = head;
        newHead = head->next;
        while (l1 != NULL) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != NULL) {
                l2->next = l2->next->next;
            }
            l1 = l1->next;
        }

        return newHead;
    }
};
// @lc code=end

