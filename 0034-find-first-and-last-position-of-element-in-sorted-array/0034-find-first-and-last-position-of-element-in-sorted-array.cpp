class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int l = 0,h = nums.size() - 1;

       auto lb = lower_bound(nums.begin(),nums.end(),target);
       auto ub = upper_bound(nums.begin(),nums.end(),target);//which will points to one step > target so we will do -1

       if(lb == nums.end() || *lb != target)
       {
        return {-1,-1};
       }

       int first = lb - nums.begin();
        int last  = ub - nums.begin() - 1; //
       return {first,last};
    }
};