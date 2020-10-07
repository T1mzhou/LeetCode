class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        int len = 0;
        for (auto p = dummy; p; p = p->next) len++;
        //cout << len << endl;
        auto p = dummy;
        for (int i = 0; i <  len - n - 1; i++) p = p->next;
        p->next = p->next->next;

        return dummy->next;
    }
};