class Solution {
public:
    bool isPalindrome(string s) {
        
        int i =0 , j = s.size()-1;

        while(i < j)
        {
            if(!isalnum(s[i]))
                i++;
            else if(!isalnum(s[j]))
                j--;
            else
            {
                if(tolower(s[i]) == tolower(s[j]))
                {
                    i++;
                    j--;
                }
                else
                    return false;
            }
        }
        return true;
        // = s.tolower();
        /*
        std::transform(s.begin(), s.end(), s.begin(),
        [](char c)
        {
            return  tolower(c);
        });

        string final;

        for(char c : s)
        {
            if(isalnum(c))
                final = final+c;
        }
       if(final.size() == 0)
            return true;
        else if(final.size() == 1)
        {
            if(isalpha(final[0]))
                return true;
        }
        cout << "final: " << final << endl;

        cout << "final size: " << final.size() << endl;
        //string ls = final;

        int start = 0;
        int end = final.size()-1;
        int checkedAtleastOnce = 0;


        //if(end == 1 && ls[end-1] == ' ')
        //    return true;
        while(start < end)
        {
            //if(ls[start] >= 97 && ls[start] <= 113)
            //{
               // if(ls[end] >= 97 && ls[end] <= 113)
                //{
                    if(final[start] == final[end])
                    {
                        checkedAtleastOnce =1;
                        start++;
                        end--;
                        continue;
                    }
                    else
                    {
                        cout << "start: " << final[start] << " end: " << final[end] << endl;
                        return false;
                    }
                //}
                //else
                //    end--;
            //}
            //else
            //    start++;
        }
        return true;*/
    }
};
