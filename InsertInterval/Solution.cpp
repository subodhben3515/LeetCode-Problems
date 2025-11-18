class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0)
            return {newInterval};
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedList;
        mergedList.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            if(mergedList.back()[1] < intervals[i][0])
            {
                mergedList.push_back(intervals[i]);
            }
            else
            {
                mergedList.back()[1] = max(mergedList.back()[1], intervals[i][1]);
            }
        }
        return mergedList;
    }
};
