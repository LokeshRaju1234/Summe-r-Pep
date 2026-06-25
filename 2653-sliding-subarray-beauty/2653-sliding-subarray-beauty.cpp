class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int arr[51] = {0};
        int ei = 0,si = 0;
        vector<int>ans;

        while(ei < nums.size())
        {
            if(nums[ei] < 0) arr[-nums[ei]]++;
            if(ei - si + 1 == k)
            {
                bool found = false;
                int count = x;
                for(int i = 50;i >= 1;i--)
                {
                    if(arr[i] >= 1)
                    {
                        //to handle duplicate elements can have freq > 1
                        count -= arr[i];
                        if(count <= 0)
                        {
                            ans.push_back(-i);
                            found  = true;
                            break;
                        }
                    }
                }

                if(!found)
                {
                    ans.push_back(0);
                }

                if(nums[si] < 0) {
                arr[-nums[si]]--;
                if(arr[-nums[si]] < 0) arr[-nums[si]] = 0;
                }
                si++;
            }

            ei++;
        }

        return ans;
    }
};