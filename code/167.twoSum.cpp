class Solution {
public:
    // 双指针
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for (int i = 0, j = numbers.size() - 1; i < j; i++ ) {
            while (i < j && numbers[i] + numbers[j] > target) j--;
            if (i < j && numbers[i] + numbers[j] == target) return {i + 1, j + 1};
        }
        return {};
    }
};