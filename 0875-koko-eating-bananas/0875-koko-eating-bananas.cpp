class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int ho) {
       int l = 1,h = *max_element(piles.begin(),piles.end());

       long long ans = 0;

       while(l <= h)
       {
        int mid = l + (h - l) / 2;

        //checking that if it is possible to eat banannas with mid speed so this will be added to our ans everytime
        if(possible(piles,mid,ho))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

       }

       return ans;
    }

    bool possible(vector<int>& piles,int hourly, int ho)
    {
        long long totalhours = 0;

        for(int ele : piles)
        {
            totalhours += ceil((double) ele / (double) hourly);
        }

        return totalhours <= ho;
    }
};