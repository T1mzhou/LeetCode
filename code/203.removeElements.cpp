class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* notEqual = dummy;
        
        while (notEqual->next != NULL) {
            if (notEqual->next->val == val) notEqual->next = notEqual->next->next;
            else notEqual = notEqual->next;
        }
        return dummy->next;
    }
};