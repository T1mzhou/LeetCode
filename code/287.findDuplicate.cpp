class Solution {
public:
    // 图论，和链表成环问题类似，找环入口
    int findDuplicate(vector<int>& nums) {
       int a = 0, b = 0;
       while (true) {
           a = nums[a];
           b = nums[nums[b]];
           if (a == b) {
               a = 0;
               while (a != b) {
                   a = nums[a];
                   b = nums[b];
               }
               return a;
           }
       } 
       return -1;
    }
};