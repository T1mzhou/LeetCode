int candy(vector<int>& ratings) {
    int size = ratings.size() + 1;
    ratings.push_back(INT_MAX);
    vector<int> nums(size, 1);
    stack<int> s;
    s.push(0);    
    int res = 0;

    for (int i = 1; i < size; ++i) {
        while (!s.empty()) {
            if (ratings[i] <= ratings[s.top()]) {
                break;
            } else {
                int index = s.top();
                s.pop();
                if (index < size - 1 && ratings[index] > ratings[index + 1]) {
                    nums[index] = max(nums[index], nums[index + 1] + 1);
                }
                if (index > 0 && ratings[index] > ratings[index - 1]) {
                    nums[index] = max(nums[index], nums[index - 1] + 1);
                }
                res += nums[index];
            }
        }
        s.push(i);
    }
    return res;
 }
