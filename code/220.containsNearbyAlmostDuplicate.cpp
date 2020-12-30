class Solution {
public:
    typedef long long LL;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<LL> S;
        S.insert(1e18), S.insert(-1e18);
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (i - j > k) S.erase(S.find(nums[j++]));
            int x = nums[i];
            auto it = S.lower_bound(x);
            if (*it - x <= t) return true;
            --it;
            if (x - *it <= t) return true;
            S.insert(x);
        }
        return false;
    }
};