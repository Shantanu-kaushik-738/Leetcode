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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* pre = nullptr;
        ListNode* curr = slow;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        int ans = 0;
        slow = head;
        fast = pre;
        while (slow && fast) {
            ans = max(ans, (slow->val + fast->val));
            slow = slow->next;
            fast = fast->next;
        }
        return ans;
    }
};
