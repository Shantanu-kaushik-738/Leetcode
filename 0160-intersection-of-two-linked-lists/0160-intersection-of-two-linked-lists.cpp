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
    ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
        unordered_map<ListNode*, int> mpp;

        ListNode* temp = head1;

        while (temp != NULL) {
            mpp[temp] = 1;
            temp = temp->next;
        }

        temp = head2;
        while (temp != NULL) {
            if (mpp.find(temp) != mpp.end()) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};