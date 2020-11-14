class Solution {
public:
    int Max(int a, int b, int c) {
        return max(max(a, b), c);
    }
    
    int Min(int a, int b, int c) {
        return min(min(a, b), c);
    }
    
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int numsMax = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            int a = curMax * nums[i];
            int b = curMin * nums[i];
            int c = nums[i];
            curMax = max(max(a, b), c);
            curMin = min(min(a, b), c);
            numsMax = max(numsMax, curMax);
        }
        return numsMax;
    }
};