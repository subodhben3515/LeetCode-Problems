class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        /*unordered_set<int> us (nums.begin(), nums.end());

        return us.size() < nums.size();*/
        unordered_map<int,int> mp;

        for(int i : nums)
        {
            if(mp[i] == 0)
                mp[i]++;
            else
                return true;
        }
        return false;
        
/*
        auto itr = find_if(mp.begin(), mp.end(), 
        [](auto pair)
        {
            return pair.second > 1;
        });
        if(itr != mp.end())
            return true;
        else
            return false;*/
    }
};
