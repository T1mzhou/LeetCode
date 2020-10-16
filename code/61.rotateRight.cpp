class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k <= 0) return head;
        ListNode* end = head;
        int n = 1;
        for (; end->next != NULL; end = end->next) ++n;
        end->next = head;
        
        k%=n;
        ListNode* newEnd = head;
        for (int i = 0; i < n-k-1; ++i) newEnd = newEnd->next;
        ListNode* newHead = newEnd->next;
        newEnd->next = NULL;
        return newHead;
    }
};