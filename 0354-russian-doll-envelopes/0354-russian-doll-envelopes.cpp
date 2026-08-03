class Solution {
public:
    int b(vector<int>& dp,vector<vector<int>>& envelopes)
    {
        int s = 0;
        
        for(auto& e : envelopes)
        {

        int l = 0;int r = s; 
        while(l != r)
        {
            int mid = (l + r) >> 1;
            if(dp[mid] < e[1])
            {
               l = mid + 1; 
            }
            else
            {
                r = mid;
            }
        }

        dp[l] = e[1];
        if(l == s) s++;

        }

        return s;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end(),[] (const vector<int> &a,const vector<int> &b)
        {
            if(a[0] == b[0])
            {
                return a[1] > b[1];
            }
            return a[0] < b[0]; 
        });

        int n = envelopes.size();
        vector<int> dp(n + 1);
        
        int f = b(dp,envelopes);

        return f;
    }
};