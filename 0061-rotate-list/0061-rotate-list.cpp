class Solution {
private:
    ListNode* findl(ListNode* head, int k) {
        int cnt = 1;

        while (head) {
            if (cnt == k) {
                return head;
            }
            cnt++;
            head = head->next;
        }
        return head;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        
        ListNode* tail = head;
        int len = 1;

        while (tail->next) {
            len++;
            tail = tail->next;
        }

        if (k % len == 0) {
            return head;
        }
        k %= len;

        tail->next = head;
        ListNode* last = findl(head, len - k);

        head = last->next;
        last->next = NULL;

        return head;
    }
};
