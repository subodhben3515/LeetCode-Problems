class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size())
            return false;
        bool found = false;
        for(int i = 0; i < ransomNote.size(); i++)
        {
            found = false;
            for(int j = 0; j < magazine.size(); j++)
            {
                if(ransomNote[i] == magazine[j])
                {
                    magazine[j] = toupper(magazine[j]);
                    found = true;
                    break;
                }
            }
            if(found == false)
                return false;
        }
        return true;
    }
};

// Optimized

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;

        for(char c: magazine)
            mp[c]++;

        for(char c : ransomNote)
        {
            if(mp[c] <= 0)
                return false;
            mp[c]--;
        }
        return true;
    }
};
