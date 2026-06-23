class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalSum = 0;
        int n = nums.size();
        for(int ele : nums)
        {
            totalSum = (totalSum + ele) % p;
        }

        if(totalSum == 0) return 0;
        unordered_map<int,int>mp;
        mp[0] = -1; //if all ele will be divisble by p
        int target = totalSum % p;
        int currsum = 0,minLen = n;
        for(int i = 0;i < n;i++)
        {
            currsum = (currsum + nums[i]) % p;

            int needed = (currsum - target + p) % p;

            if(mp.find(needed) != mp.end())
            {
                minLen = min(minLen,i - mp[needed]);
            }

            mp[currsum] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};