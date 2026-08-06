class Solution {
public:
   vector<vector<int>> dp;
    int solve(string& text1,string& text2,int i,int j)
    {
        if(i >= text1.size() || j >= text2.size())
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(text1[i] == text2[j])
        {
            return 1 + solve(text1,text2,i+1,j+1);
        }

        int m1 = solve(text1,text2,i + 1,j);
        int m2 = solve(text1,text2,i,j + 1);

        return dp[i][j] = max(m1,m2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size() + 1,vector<int>(text2.size() +1,-1));
        return solve(text1,text2,0,0);
    }
};