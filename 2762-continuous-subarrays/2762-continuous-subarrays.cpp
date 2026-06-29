class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long ans = 0;
        int n = nums.size();
        int ei = 0,si = 0;

        deque<int>min;
        deque<int>max;
        
        while(ei < n)
        {
            while(!min.empty() && nums[min.back()] > nums[ei])
            {
                min.pop_back();
            }

            min.push_back(ei);
            while(!max.empty() && nums[max.back()] < nums[ei])
            {
                max.pop_back();
            }
            max.push_back(ei);

            while(nums[max.front()] - nums[min.front()] > 2)
            {
                //we need to remove the old indices while shirinking the window as that will be not part of our window
                if(min.front() == si)
                {
                    min.pop_front();
                }

                if(max.front() == si)
                {
                    max.pop_front();
                }
                //shrink the window until it is valid
                si++;
            }
            //in this range all paris are guaranteed that diff will be <= 2 by performing diff btw max and min element in the window
            ans += (ei - si + 1);
            ei++;
        }

        return ans;
    }
};