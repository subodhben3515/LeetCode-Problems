class Solution {
public:

/*

Pattern
1 ss -> 1 op
2 ss -> 3 op (1+2)
3 ss -> 6 op (1+2+3)
4 ss -> 10 op(1+2+3+4)

*/
    int numSub(string s) {
        int consecutive = 0;
        int result = 0;

        for(char &ch : s)
        {
            if(ch == '0')
            {
                consecutive = 0;
            }
            else
            {
                consecutive++;
                result = (result + consecutive) % 1000000007;
            }
        }
        return result;
    }
};
