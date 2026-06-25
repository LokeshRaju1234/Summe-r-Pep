class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int ei = 0,si = 0;
        long long res = 0;
        long long ans = 0;
        while(ei < nums.size())
        {
            
            res += mp[nums[ei]];
            mp[nums[ei]]++;

            while(res >= k)
            {
                ans += (n - ei);
                mp[nums[si]]--;
                res -= mp[nums[si]];
                si++;
            }

            ei++;
        }

        return ans;
    }
};