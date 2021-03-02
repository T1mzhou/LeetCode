class Solution {
public:
    // 双指针
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (auto x : nums) {
            if (x)
                nums[k++] = x;
        }
        while (k < nums.size()) nums[k++] = 0;
    }
};