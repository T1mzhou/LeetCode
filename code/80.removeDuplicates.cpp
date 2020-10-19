class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int k = 0;
         for (auto x : nums) if (k < 2 || (nums[k-1] != x || nums[k - 2] != x)) {
             nums[k++] = x;
         }
         return k;
    }
};