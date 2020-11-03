class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(),nums.end()); //装进集合,去重
        for(int val:nums) //一次扫描数组
        {
            if(!s.count(val)) continue; //不存在表明已被处理过
            s.erase(val); //将当前值从集合中除去以免之后重复被处理
            int pre = val - 1, next = val + 1;
            while (s.count(pre)) s.erase(pre--); //对当前值向两边开始寻找，直至不存在
            while (s.count(next)) s.erase(next++);
            res = max(res,next-pre-1);//更新最长连续子序列
        }
        return res;
    }
};