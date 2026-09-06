class Solution {
public:
vector<vector<int>> dp;
    int solve(int i,int j,string &s,string &t){

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(j == t.size()){
            return  1;
        }

        if(i == s.size()){
            return 0;
        }

        int k1 = 0,k2 = 0;

        if(s[i] == t[j]){
        k1  = solve(i + 1,j + 1,s,t);
        k2 = solve(i + 1,j,s,t);
        }
        k2  = solve(i + 1,j,s,t);
        return dp[i][j] = k1 + k2;
        
    }
    int numDistinct(string s, string t) {
        dp.assign(s.size() + 1,vector<int>(t.size() + 1,-1));
        return solve(0,0,s,t);
    }
};