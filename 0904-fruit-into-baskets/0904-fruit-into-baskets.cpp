class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;

        int left = 0;
        int maxans = INT_MIN;
        for(int right = 0;right < fruits.size();right++)
        {
            mp[fruits[right]]++;
            //we need more than two buckets to hold the fruits so remove the fruit from left
            while(mp.size() > 2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            maxans = max(maxans,right - left + 1);
        }

        return maxans;
    }
};