class Solution {
public:
    int k, ans;

    int kthSmallest(TreeNode* root, int _k) {
        k = _k;
        dfs(root);
        return ans;
    }

    bool dfs(TreeNode* root) {
        if (!root) return false;;
        if (dfs(root->left)) return true;
        if (--k == 0) {
            ans = root->val;
            return true;
        }
        return dfs(root->right);

    }
};