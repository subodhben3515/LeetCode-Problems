#include <algorithm>

class Solution {
public:
    string addBinary(string a, string b) {

        int carry = 0, i = a.length()-1, j = b.length()-1;

        string res("");
        while(i >=0 or j >= 0)
        {
            int bit1{0}, bit2{0};
            if(i>=0)
            {
                bit1 = a[i]-'0';
            }
            else
            {
                bit1 = 0;
            }

            if(j>=0)
            {
                bit2 = b[j]-'0';
            }
            else
            {
                bit2 = 0;
            }

            int sum = bit1+bit2+carry;
            int result = sum%2;
            carry = sum/2;
            res = to_string(result) + res;
            --i;
            --j;

        }
        if(carry > 0)
            res = to_string(carry)+res;
        return res;
    }
};
