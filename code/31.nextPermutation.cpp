class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int n = nums.size();
        int p = n - 2;
        while (p >= 0 && nums[p] >= nums[p+1]) --p;
        
        if (p >= 0) {
            int i = n - 1;
            while (i > p && nums[i] <= nums[p]) --i;
            swap(nums, i, p);
        }
        for (int i = p+1, j = n-1; i < j; ++i, --j) {
            swap(nums, i, j);
        }
    }
};