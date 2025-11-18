class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentMax = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            currentMax = max(currentMax, 0) + nums[i];

            maxSum = max(maxSum, currentMax);
        }
        return maxSum;
    }
};
