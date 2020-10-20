class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)    return nullptr;

        for (ListNode *prev = head, *cur = head->next; cur; cur = prev->next) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
                delete cur;
            } else {
                prev = cur;
            }
        }
        return head;
    }
};