class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;
        ListNode* smaller = new ListNode(0);
        ListNode* greater = new ListNode(0);
        ListNode* ps = smaller;
        ListNode* pg = greater;
        
        for (ListNode* p = head; p != NULL; p = p->next) {
            if (p->val < x) {
                ps->next = p;
                ps = ps->next;
            } else {
                pg->next = p;
                pg = pg->next;
            }
        }
        ps->next = greater->next;
        pg->next = NULL;
        return smaller->next;
    }
};