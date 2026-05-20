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
    ListNode* cp(ListNode* t1, ListNode* t2, int d) {

        while (d) {
            d--;
            t2 = t2->next;
        }

        while (t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
    ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
        unordered_map<ListNode*, int> mpp;

        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        int n1 = 0;
        int n2 = 0;

        while (temp1 != NULL) {
            n1++;
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            n2++;
            temp2 = temp2->next;
        }

        if (n1 < n2) {
            return cp(head1, head2, n2 - n1);
        } else {
            return cp(head2, head1, n1 - n2);
        }
        return NULL;
    }
};