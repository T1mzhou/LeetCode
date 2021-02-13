class Solution {
private:
    int get(vector<int>& nums, int k, int t) {
        int res = 0;
        for (auto x : nums) {
            if ((x >> k & 1) == t) {
                res ^= x;
            }
        }
        return res;
    }
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = 0;
        for (auto x : nums) ab ^= x;
        int k = 0;
        while ((ab >> k & 1) == 0) k++;
        return {get(nums, k, 0), get(nums, k, 1)};
    }
};