class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(),weights.end(),0);//to get the total sum of the array
        int ans = 0;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            //checking that with mid capacity is it possible to load the wei into ship within D days 
            if(possible(weights,mid,days))
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

    bool possible(vector<int>& weights,int cap, int days)
    {
        int day = 1;
        int load = 0;

        for(int i = 0;i < weights.size();i++)
        {
            if(load + weights[i] > cap)
            {
                load = weights[i];
                day++;
            }
            else
            {
                load += weights[i];
            }
        }

        return day <= days;
    }
};