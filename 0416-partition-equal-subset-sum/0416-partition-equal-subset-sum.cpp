class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //will get 
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum %2 == 1) return false;

        int t = sum / 2;
        int n = nums.size();
        
        vector<vector<bool>>dp(n + 1,vector<bool>(t + 1,false));

        for(int i = 0;i <= n;i++)
        {
            dp[i][0] = true;
        }

        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= t;j++)
            {
                if(j - nums[i - 1] >= 0)
                {
                    dp[i][j]  = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][t];
    }
};