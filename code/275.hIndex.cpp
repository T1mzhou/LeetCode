class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (citations[n - mid] >= mid) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};