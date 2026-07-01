class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int len = INT_MAX;
        long long sum = 0;
        int n = nums.size();
        vector<long long>pref(n + 1,0);
        for(int i = 0;i < n;i++)
        {
            pref[i + 1] = pref[i] + nums[i];
        }

        deque<int>dq;

        for(int i = 0;i < pref.size();i++)
        {
            //we need the smaller prefix so that we will get larger sum may be it will 
            //be useful for future subarray prefix sum
            while(!dq.empty() && pref[i] <= pref[dq.back()])
            {
                dq.pop_back();
            }

            //i need the smaller subarray with sum >= k it comes from choosing smaller 
            //prefix sum and if it satisfies add the length and pop it from deque bcz 
            //it even increases the length for future index like 4 - 0 and 5 - 0 and 6 - 0 the length increases everytime so remove the old ones and add new pref sum
            while(!dq.empty() && pref[i] - pref[dq.front()] >= k)
            {
                len = min(len,i - dq.front());
                dq.pop_front();
            }

            dq.push_back(i);
        }

        return len == INT_MAX ? -1 : len;
    }
};