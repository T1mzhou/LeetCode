class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int d[nums.size()];
        d[0] = nums[0];
        d[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); ++i) {
            d[i] = max(d[i-1], d[i-2]+nums[i]);
        }
        return d[nums.size()-1];
    }
};