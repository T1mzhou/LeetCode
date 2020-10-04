class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          unordered_map<int, int> heap;
          for (int i = 0; i < nums.size(); i++) {
              int r = target - nums[i];
              if (heap.count(r)) return { heap[r], i};
              heap[nums[i]] = i;
          }
          return {0, 0};
    }
};