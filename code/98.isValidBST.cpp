class Solution {
public:
    
    bool isVaildBSTBound(TreeNode* root, TreeNode* lower, TreeNode* upper)
    {
        if (root == NULL) return true;
        if (lower != NULL && lower->val >= root->val) return false;
        if (upper != NULL && upper->val <= root->val) return false;
        return isVaildBSTBound(root->left, lower, root) && isVaildBSTBound(root->right, root, upper);
    }
    bool isValidBST(TreeNode* root) {
        return isVaildBSTBound(root, NULL, NULL);
    }
    
};