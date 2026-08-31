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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        int l = 0, r = 0, idx = 1; // first, last, current critical index
        int d = 1e9;               // distance

        while (curr->next) {
            if (((curr->val < prev->val) && (curr->val < curr->next->val)) ||
                ((curr->val > prev->val) && (curr->val > curr->next->val))) {
                if (r == 0) { // first point
                    r = idx;
                    l = idx;
                } else {
                    d = min(d, idx - r);
                    r = idx;
                }
            }
            idx++;
            prev = curr;
            curr = curr->next;
        }
        if (d == 1e9) return {-1, -1}; // no critical points
        return {d, r - l};
    }
};
