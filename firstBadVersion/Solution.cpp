// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1)
            return n;

        int i =0, j = n ;
        int mid = 0, ans = 0;

        while(i<=j)
        {
            mid = i + (j-i)/2;

            if(isBadVersion(mid))
            {
                ans = mid;
                j = mid - 1;
            }

            else
            {
                cout << "i: " << i << endl;
                i = mid + 1;

            }
            
        }
        return ans;
    }
};
