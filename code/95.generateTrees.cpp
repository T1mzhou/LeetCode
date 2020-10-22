class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) return {NULL};
        vector<TreeNode*> res;

        for (int i = l; i <= r; i++) {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto l : left) {
                for (auto r : right) {
                    auto root = new TreeNode(i);
                    root->left = l, root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};