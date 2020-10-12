class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int *max_left = new int[n]();
        int *max_right = new int[n]();

        for (int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i - 1], height[i - 1]);
            max_right[n - 1 - i] = max(max_right[n - i], height[n - i]);
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int high = min(max_left[i], max_right[i]);
            if (high > height[i]) {
                sum += high - height[i];
            }
        }
        delete[] max_left;
        delete[] max_right;
        return sum;
    }
};