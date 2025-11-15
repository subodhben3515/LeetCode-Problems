class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxElement = 0;
        int maxFreq = 0;
        for(int t: nums)
            mp[t]++;
        
        for(auto it: mp)
        {
            if(maxFreq < it.second)
            {
                maxElement = it.first;
                maxFreq = it.second;
            }
        }
        return maxElement;
    }
};
