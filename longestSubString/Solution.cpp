class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1)
        return 1;
        char frequency[128]{0};

        int maxLength = 0;
        int size = s.size();

        int left = 0;
        
        for(int right = 0; right< size ; right++)
        {
            frequency[s[right]]++;

            while(frequency[s[right]] >1)
            {
                frequency[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};
