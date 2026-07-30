class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int t,vector<int>& coins)
    {
        if(t == 0)
        {
            return 0;
        }

        if(i >= coins.size())
        {
            return INT_MAX;
        }

        if(dp[i][t] != -1)
        {
            return dp[i][t];
        }

        int nt = solve(i + 1,t,coins);
        int tk = INT_MAX;
        if(t - coins[i] >= 0)
        {
            int res = solve(i,t - coins[i],coins);
            if(res != INT_MAX)
            {
                tk = 1 + res;
            }
        }

        return dp[i][t] = min(nt,tk);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(),vector<int>(amount + 1,-1));
        int ans = solve(0,amount,coins);
        return (ans == INT_MAX) ? -1 : ans;
    }
};