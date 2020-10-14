class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxnumber = INT_MIN;
        int cur = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            cur = cur <= 0 ? nums[i] : (cur + nums[i]);
            maxnumber = max(maxnumber, cur);
        }
        return maxnumber;
    }
};