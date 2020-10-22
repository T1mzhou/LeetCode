class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto a = dummy;
        for (int i = 0; i < m - 1; i++) a = a->next;
        auto  b = a->next, c = b->next;
        for (int i = 0; i < n - m; i++) {
            auto t = c->next;
            c->next = b;
            b = c, c = t;
        }

        a->next->next = c;
        a->next = b;
        return dummy->next;
    }
};