class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < n; i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // Current interval is already covered
            if(!ans.empty() && end <= ans.back()[1]) {
                continue;
            }

            // Find all overlapping intervals
            for(int j = i + 1; j < n; j++) {

                if(intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                }
                else {
                    break;
                }
            }

            // Add merged interval
            ans.push_back({start, end});
        }

        return ans;
    }
};