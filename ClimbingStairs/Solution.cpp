class Solution {
    vector<int> memo;//46, -1);
public:
    Solution() : memo(46, -1) {};
    int climbStairs(int n) {
        
        if(n == 1 || n == 0)
            return 1;
        if(memo[n] != -1)
            return memo[n];
        return memo[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};
