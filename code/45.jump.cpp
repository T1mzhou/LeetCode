class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return 0;
        int n = nums.size();
        int maxNums = 0;
        int jumps = 0;
        int curEnd = 0;
        for (int i = 0; i < n; ++i) {
            if (maxNums >= n-1) return jumps+1;
            if (i > curEnd) {
                ++jumps;
                curEnd = maxNums;
            }
            maxNums = max(maxNums, i+nums[i]);
        }
        return -1;
    }
};