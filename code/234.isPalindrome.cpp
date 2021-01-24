/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> s;
        for (ListNode* p = head; p != NULL; p = p->next)
            s.push(p);
        for (ListNode* p = head; p != NULL; p = p->next) {
            ListNode* t = s.top();
            s.pop();
            if (p->val != t->val)
                return false;
        }
        return true;
    }
   
};