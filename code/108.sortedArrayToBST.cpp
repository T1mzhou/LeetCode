class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }
    template<typename RandomAccessIterator>
    TreeNode* sortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last) {
        const auto length = distance(first, last);
        if (length <= 0)    return nullptr;
        auto mid = first + length / 2;
        TreeNode* root = new TreeNode(*mid);
        root->left = sortedArrayToBST(first, mid);
        root->right = sortedArrayToBST(mid + 1, last);
        return root;
    }
};