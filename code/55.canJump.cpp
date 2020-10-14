class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        int n = nums.size();
        int maxNums = 0;
        for (int i = 0; i < n; ++i) {
            if (maxNums >= n-1) return true;
            if (i > maxNums) return false;
            maxNums = max(maxNums, i+nums[i]);
        }
        return false;
    }
};