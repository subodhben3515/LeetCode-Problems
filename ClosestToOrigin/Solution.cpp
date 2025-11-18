class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        sort(points.begin(), points.end(), 
        [](const vector<int>& point1, const vector<int>& point2)
        {
            auto dist1 = hypot(point1[0], point1[1]);//point1[0]*point1[0] + point1[1]*point1[1];
            auto dist2 = hypot(point2[0], point2[1]);//point2[0]*point2[0] + point2[1]*point2[1];

            return dist1 < dist2;
        });

        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};
