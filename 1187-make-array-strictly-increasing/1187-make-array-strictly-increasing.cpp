class Solution {
public:
map<string,int> dp;
    int solve(vector<int>& arr1, vector<int>& arr2,int i,int prev)
    {
        //to validate ex like case 1 -> idx 2 and prevVal 33 
        //case 2 -> idx 23 and prevVal 3 to avoid this we use space in btw index and prevVal
        string key = to_string(i) + " " + to_string(prev);
        if(i == arr1.size())
        return 0;

        if(dp.find(key) != dp.end()) return dp[key];
        int val1 = -1;
        int val2 = -1;
        if(arr1[i] > prev)
        {
            //skip
            val1 = solve(arr1,arr2,i + 1,arr1[i]);
        }

         auto it = upper_bound(arr2.begin(),arr2.end(),prev);
            if(it != arr2.end())
            {
                //if you found the value then this will be our previous value
                val2 = solve(arr1,arr2,i + 1,*it);
                if(val2 != -1)
                {
                    val2 += 1;
                }

            }
            //if we dont get any sI array 
            if(val1 == -1 && val2 == -1) return dp[key] =  -1;
            if(val1 == -1) return dp[key] =  val2;
            if(val2 == -1) return dp[key] =  val1;

            //if both calls are valid so take minimum 
            return dp[key] = min(val1,val2);
        // else
        // {
        //     auto it = upper_bound(arr2.begin(),arr2.end(),prev);
        //     if(it == arr2.end())
        //     {
        //         return dp[key] =   -1;
        //     }
        //         val2 = solve(arr1,arr2,i + 1,*it);
        //         if(val2 != -1)
        //         {
        //             val2 += 1;
        //         }
        // }
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        return solve(arr1,arr2,0,INT_MIN);
    }
};