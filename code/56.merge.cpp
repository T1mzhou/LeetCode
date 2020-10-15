class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), [=](const vector<int> & A, const vector<int> & B)->bool {return A[0] < B[0]; });
        int len = intervals.size();

	    int temp = 0;

	    for (int i = 1; i < len; ++i) {
		   if (intervals[temp][1] >= intervals[i][0]) 
			  intervals[temp][1] = max(intervals[temp][1], intervals[i][1]);
		   else {
			  result.push_back(intervals[temp]);
			  temp = i;
		   }
	     }
	result.push_back(intervals[temp]);
	return result;
    }
};