class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int evencount = 0;
        int oddcount = 0;
        for(int e : nums1){
            if(e %2 == 0){
                evencount++;
            }else{
                oddcount++;
            }
        }

        bool even = (evencount > 0) ? true : false;
        bool odd = (oddcount > 0) ? true : false;

        return odd || even;
    }
};