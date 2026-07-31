class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //will get 
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum %2 == 1) return false;

        int t = sum / 2;
        bitset<10001>b;
        b[0] = 1;

        for(int x : nums)
        {
            b |= (b << x);
        }

        return b[t];
    }
};