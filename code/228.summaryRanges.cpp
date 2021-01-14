class Solution {
public:
    // 摩尔投票法推广
    vector<int> majorityElement(vector<int>& nums) {
        int r1,r2 ,c1 = 0, c2 = 0;
        for (auto x : nums) {
            if (c1 && x == r1) c1++;
            else if (c2 && x == r2) c2++;
            else if (!c1) r1 = x, c1++;
            else if (!c2) r2 = x, c2++;
            else c1--, c2--;
        }
        c1 = 0, c2 = 0;
        for (auto x : nums) {
            if (x == r1) c1++;
            else if (x == r2) c2++;
        }

        vector<int> res;
        if (c1 > nums.size() / 3) res.push_back(r1);
        if (c2 > nums.size() / 3) res.push_back(r2);
        return res;
    }
};