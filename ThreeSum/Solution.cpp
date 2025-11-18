class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> result;
        for(int first = 0; first < nums.size()-2 && nums[first]<= 0; first++)
        {
            if(first > 0 && nums[first] == nums[first-1])
                continue;
            int i = first+1;
            int j = nums.size()-1;

            while(i < j)
            {
                int currentSum = nums[first]+nums[i]+nums[j];

                if(currentSum < 0)
                    i++;
                else if(currentSum > 0)
                    j--;
                else
                {
                    result.push_back({nums[first],nums[i],nums[j]});
                    i++;
                    j--;

                    while(i < j && nums[j] == nums[j+1])
                        j--;
                    
                    while(i < j && nums[i] == nums[i-1])
                        i++;                    
                }
            }
        }
        return result;
    }
};
