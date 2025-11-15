class Solution {
public:
    bool isAnagram(string s, string t) {

    if(s.size() != t.size())
        return false;

     sort(s.begin(), s.end());
     sort(t.begin(), t.end());

     if(s == t)
        return true;
     else
        return false;   
    }

    // Other Options, Op1
            if(s.size() != t.size())  return false;
        vector<int>st(26);
        vector<int>tt(26);
        for(auto ch : s)  st[ch-'a']++;
        for(auto ch: t) tt[ch-'a']++;
        return st == tt;

    // OP2
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        for(char c: t){
            mp[c]--;
            if(mp[c]<0){
                return false;
            }
        }
        return true;
        
    }
};
