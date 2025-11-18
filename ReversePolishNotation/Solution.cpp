class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int result = 0;

        for(auto& tk: tokens)
        {
            if(tk.size() > 1 || isdigit(tk[0]))
                s.push(stoi(tk));
            else
            {
                if(tk[0] == '+')
                {
                    int second = s.top();
                    s.pop();
                    int first = s.top();
                    s.pop();
                    s.push(first+second);
                }
                else if(tk[0] == '-')
                {
                    int second = s.top();
                    s.pop();
                    int first = s.top();
                    s.pop();
                    s.push(first-second);
                }
                else if(tk[0] == '/')
                {
                    int second = s.top();
                    s.pop();
                    int first = s.top();
                    s.pop();
                    cout << "first : " << first << " second: " << second << "\\" << "\n";
                    s.push(first/second);
                }
                else if(tk[0] == '*')
                {
                    int second = s.top();
                    s.pop();
                    int first = s.top();
                    s.pop();
                    s.push(first*second);
                }
            }
        }
        return s.top();
    }
};
