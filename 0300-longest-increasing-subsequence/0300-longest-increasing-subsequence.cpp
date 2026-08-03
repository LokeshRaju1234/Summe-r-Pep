class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n + 1);
        int s = 0;
        for(int x : nums)
        {
            int l = 0,r = s;
            while(l != r)
            {
                int mid = (l + r) >> 1;

                //2  < 5 then it is strictly incasing
                if(dp[mid] < x)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }

            dp[l] = x;
            if(l == s) s++;
        }

        return s;
    }
};