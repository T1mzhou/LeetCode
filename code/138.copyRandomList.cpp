class Solution {
public:
    Node* copyRandomList(Node* head) {
        for (Node* cur = head; cur != nullptr; ) {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        for (Node* cur = head; cur != nullptr; ) {
            if (cur->random != NULL) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        } 

        Node dummy(-1);
        for (Node* cur = head, *new_cur = &dummy; cur != nullptr; ) {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};