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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* crr = dummy;

        int car = 0;
        while (t1 || t2) {
            int sum = car;

            if (t1) {
                sum += t1->val;
            }
            if (t2) {
                sum += t2->val;
            }

            ListNode* nNode = new ListNode(sum % 10);
            car = sum / 10;

            crr->next = nNode;
            crr = crr->next;

            if (t1) {
                t1 = t1->next;
            }
            if (t2) {
                t2 = t2->next;
            }
        }

        if (car) {
            ListNode* nNode = new ListNode(car);
            crr->next = nNode;
        }
        return dummy->next;
    }
};