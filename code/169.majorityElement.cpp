class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int r, c = 0;
        for (auto x : nums) {
            if (!c) r = x, c = 1;
            else if (r == x) c++;
            else c--;
        }
        return r;
    }
};