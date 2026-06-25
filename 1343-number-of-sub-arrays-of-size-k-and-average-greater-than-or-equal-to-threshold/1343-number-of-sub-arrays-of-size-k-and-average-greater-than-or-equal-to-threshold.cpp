class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
       int sum = 0;
       int num = threshold * k; //(sum / k) >= threshhold then ->sum >= threshhold * k; 
       int res = 0;
       
       int ei = 0,si = 0;
       while(ei < arr.size())
       {
        sum += arr[ei++];
        if(ei - si == k)
        {
            if(sum >= num)
            {
                res++;
            }

            sum -= arr[si++];
        }
       }

       return res;
    }
};