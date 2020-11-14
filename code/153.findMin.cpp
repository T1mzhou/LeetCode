class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums[r] > nums[l]) return nums[0];
        while (l < r) {
            int mid  = l + r >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};