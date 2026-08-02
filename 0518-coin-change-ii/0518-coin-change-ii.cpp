class Solution {
public:
    vector<vector<int>> dp;
    int solve(int amount,vector<int>& coins,int i)
    {
        if(amount == 0)
        {
            return 1;
        }

        if(i >= coins.size())
        {
            return 0;
        }

        if(dp[i][amount] != -1)
        {
            return dp[i][amount];
        }
        
        int nt = solve(amount,coins,i + 1);
        int t = 0;
        //whenever the amount is greater than the coins so we can use that
        if(amount >= coins[i])
        {
            t = solve(amount - coins[i],coins,i);
        }

        //gives the number of ways
        return dp[i][amount] = nt + t;
    }
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        dp.assign(n + 1,vector<int>(amount + 1,-1));
        return solve(amount,coins,0);
    }
};