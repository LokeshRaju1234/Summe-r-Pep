class Solution {
public:
map<string,int> dp;
    int solve(vector<int>& arr1, vector<int>& arr2,int i,int prev)
    {
        //we have processed the array completely
       if(i == arr1.size()) return 0;
       
       string key = to_string(i) + " " + to_string(prev);   

       if(dp.find(key) != dp.end()) return dp[key];

       int ans  = INT_MAX;
       //not take
       if(arr1[i] > prev)
       {
            int nt = solve(arr1,arr2,i + 1,arr1[i]);
            if(nt != -1)
            {
                ans = min(ans,nt);
            }
       }

       //take it
       auto it = upper_bound(arr2.begin(),arr2.end(),prev);
        if(it != arr2.end())
        {
            int take = solve(arr1,arr2,i + 1,*it);
            if(take != -1)
            {
                take++;
                ans = min(take,ans);
            }
        }

        return dp[key] = ans == INT_MAX ? -1 : ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
         // Remove duplicates from arr2
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        return solve(arr1,arr2,0,INT_MIN);
    }
};