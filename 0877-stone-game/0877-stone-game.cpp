class Solution {
public: 
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp;
        dp.assign(n,vector<int>(n,1e9 + 7));

        for(int i = 0;i < n;i++)   
        {
            //when there is only one index we consider that element
            dp[i][i] = piles[i];
        }

        //dp[i][j] = max score difference i can get while playing on piles[i ... j]
        //fill the larger intervals after filling the base cases
        for(int i = n - 1;i >= 0;i--)
        {
            for(int j =  i + 1;j < n;j++)
            {
                //every player has two choices if he takes i and p2 -> i+1 ..j
                //if p1 chooses j then p2 will play on i ... j - 1
                int left = piles[i] - dp[i + 1][j];
                int right = piles[j] - dp[i][j - 1];

                //because the player is playing optimally
                dp[i][j] = max(left,right);
            }
        }

        return dp[0][n - 1] > 0;
    }
};