class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int i) {
        if(i==nums.size())
             res.push_back(nums);
        for(int j = i; j < nums.size(); ++j) {
            swap(nums[i],nums[j]);              // 利用俩次交换巧妙处理不可重复选的问题
            backtrack(res, nums, i+1);
            swap(nums[i],nums[j]);           
        }              
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > res;
        backtrack(res, nums, 0);
        return res;
    }
};