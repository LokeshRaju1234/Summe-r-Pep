class Solution {
public:
    // vector<vector<bool>>dp;
    // int solve(int i,int t,vector<int>& coins)
    // {
    //     if(t == 0)
    //     {
    //         return 0;
    //     }

    //     if(i >= coins.size())
    //     {
    //         return INT_MAX;
    //     }

    //     if(dp[i][t] != -1)
    //     {
    //         return dp[i][t];
    //     }

    //     int nt = solve(i + 1,t,coins);
    //     int tk = INT_MAX;
    //     if(t - coins[i] >= 0)
    //     {
    //         int res = solve(i,t - coins[i],coins);
    //         if(res != INT_MAX)
    //         {
    //             tk = 1 + res;
    //         }
    //     }

    //     return dp[i][t] = min(nt,tk);
    // }

    vector<vector<int>>dp;
    int coinChange(vector<int>& coins, int amount) {
        int INF = 1e9 + 7;
        int n = coins.size();
        dp.assign(n + 1,vector<int>(amount + 1,INF));

        for(int i = 0;i <= n;i++)
        {
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n;i++)
        {
            for(int j = 1;j <= amount;j++)
            {
                if(j - coins[i - 1] >= 0)
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]],dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if(dp[n][amount] != INF)
        {
            return dp[n][amount];
        }

        return -1;
    }
};