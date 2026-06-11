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
private:
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* findk(ListNode* temp, int k) {
        while (temp && --k) {
            temp = temp->next;
        }
        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp) {
            ListNode* kth = findk(temp, k);
            if (kth == NULL) {
                if (prev) {
                    prev->next = temp;
                }
                break;
            }
            ListNode* next = kth->next;
            kth->next = NULL;

            ListNode* nhead = rev(temp);
            if (temp == head) {
                head = nhead;
            } else {
                prev->next = nhead;
            }

            prev = temp;
            temp = next;
        }
        return head;
    }
};