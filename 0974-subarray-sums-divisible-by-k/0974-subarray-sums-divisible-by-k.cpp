class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix = 0,ei = 0;
        
        unordered_map<int,int> mp;
        int count = 0;
        
        mp[0] = 1;
        int n = nums.size();
        while(ei < n)
        {
            prefix += nums[ei++];

            int rem = (prefix % k + k) % k;

            count += mp[rem];
            mp[rem]++;
        }

        return count;
    }
};