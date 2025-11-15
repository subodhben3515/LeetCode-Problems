class Solution {
public:
    bool isValid(string s) {

        if(s.length() % 2 != 0)
        return false;

        auto isClosingBrace = [](char c )
        {
            return c == ')' || c == '}' || c == ']';
        };

        auto addOpp = [](char c)
        {
            if(c == '(')
            return ')';
            else if (c == '{')
            return '}';
            else if (c == '[')
            return ']';
            else
            return c;
        };

        stack<char> st;
        for(char ch : s)
        {
            if(st.empty())
            {
                //cout << "Inserting: " << ch;
                if(isClosingBrace(ch))
                    return false;

                st.push(addOpp(ch));
                continue;
            }
            else
            {
                if(isClosingBrace(ch))
                {
                    auto tmp = st.top();
                    if(tmp == ch)
                        st.pop();
                    else
                        return false;
                }
                else
                    st.push(addOpp(ch));

                // cout << "Comparing tmp: " << tmp << " ch: " << ch  << "diff: " << ch-tmp << endl;
                // if((ch - tmp != 1) && (ch - tmp != 2))
                // {
                //     return false;
                // }
                // st.pop();
            }
        }
        if(st.empty())
        return true;
        else
        return false;
    }
};



class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else{
                if(stk.empty())
                    return false;
                else if(s[i]==')' && stk.top()=='(')
                    stk.pop();
                else if(s[i]=='}' && stk.top()=='{')
                    stk.pop();
                else if(s[i]==']' && stk.top()=='[')
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};
