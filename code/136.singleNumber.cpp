class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num = 0; num < nums.size(); num++) {
            result ^= nums[num];
        }
        return result;
    }
};