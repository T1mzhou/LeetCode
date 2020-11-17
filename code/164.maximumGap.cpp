class Bucket {
public:
    bool used = false;
    int minv = numeric_limits<int>::max();
    int maxv = numeric_limits<int>::min();
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();

        int minv = INT_MAX, maxv = INT_MIN;
        for (int i = 0; i < n; ++i) {
            minv = min(minv, nums[i]);
            maxv = max(maxv, nums[i]);
        }

        int bucksize = max(1, (maxv - minv) / (n - 1));
        int numbuck = (maxv - minv) / bucksize + 1;
        vector<Bucket> buckets(numbuck);
        for (int i = 0; i < n; ++i) {
            int ibuck = (nums[i] - minv) / bucksize;
            buckets[ibuck].used = true;
            buckets[ibuck].minv = min(buckets[ibuck].minv, nums[i]);
            buckets[ibuck].maxv = max(buckets[ibuck].maxv, nums[i]);
        }

        int mdiff = 0;
        int prev_maxv = minv;
        for (int i = 0; i < buckets.size(); ++i) {
            if (!buckets[i].used) continue;

            mdiff = max(mdiff, buckets[i].minv - prev_maxv);
            prev_maxv = buckets[i].maxv;
        }

        return mdiff;
    }
};