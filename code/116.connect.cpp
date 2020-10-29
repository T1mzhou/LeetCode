class Solution {
public:
    Node* connect(Node* root) {
        return connect(root, NULL);
    }
private:
    Node* connect(Node* root, Node *sibling) {
        if (root == nullptr) {
            return root;
        } else {
            root->next = sibling;
        }
        connect(root->left, root->right);
        if (sibling) {
            connect(root->right, sibling->left);
        } else {
            connect(root->right, nullptr);
        }
        return root;
    }
};