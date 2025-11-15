class Solution {
public:
    int longestPalindrome(string s) {
        int freq[192]{};
        int res = 0;

        for(char c :s)
            freq[c]++;

        for(int c: freq)
        {
            res +=  (c/2)*2;
        }

        if(res < s.length())
            res += 1;

        return res;
    }
};
