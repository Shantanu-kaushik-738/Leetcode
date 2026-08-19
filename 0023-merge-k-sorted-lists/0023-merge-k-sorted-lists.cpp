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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq; // min heap
        for (auto& i : lists) {
            if (i) pq.push({i->val, i});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            auto p = pq.top();
            temp->next = p.second;
            pq.pop();

            if (p.second->next) pq.push({p.second->next->val, p.second->next});
            temp = temp->next;
        }
        return dummy->next;
    }
};
