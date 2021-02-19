class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingNumber = 0;
        for (int i = 0; i < nums.size(); ++i) {
            missingNumber = missingNumber - nums[i] + i;
        }
        return missingNumber + nums.size();
    }
};
