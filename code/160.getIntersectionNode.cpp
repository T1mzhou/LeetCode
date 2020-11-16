class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0; int lenB = 0;
        for (ListNode* p = headA; p != NULL; p = p->next, ++lenA);
        for (ListNode* p = headB; p != NULL; p = p->next, ++lenB);
        ListNode* p = headA;
        ListNode* q = headB;
        
        if (lenA > lenB) 
            for (int i = 0; i <lenA - lenB;++i) p = p->next;
        else
             for (int i = 0; i <lenB - lenA;++i) q = q->next;
        while ( p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
