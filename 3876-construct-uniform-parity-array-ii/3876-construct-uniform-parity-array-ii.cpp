class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
         int minOdd = 1e8 + 5;
         int minEven = 1e8 + 5;

         for(int e : nums1){
            if(e % 2 == 0){
                minEven = min(minEven,e);
            }else{
                minOdd = min(minOdd,e);
            }
         }

         if(minOdd == 1e8 + 5) return true;

         for(int e : nums1){
            if(e %2 == 0 && e < minOdd){
                return false;
            }
         }

         return true;
    }
};