class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp.assign(nums.size() + 1, -1);
        return solve(0,nums,nums.size());
    }

    int solve(int i,vector<int>& nums,int n)
    {
        if(i >= n)
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        int nottake = solve(i + 1,nums,n);
        int take = nums[i] + solve(i + 2,nums,n);

        return dp[i] = max(nottake,take);
    }
};