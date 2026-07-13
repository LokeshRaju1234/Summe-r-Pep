class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        vector<bool> used(baskets.size(),false);
        for(int i = 0;i < fruits.size();i++)
        {
            for(int j = 0;j < fruits.size();j++)
            {
                if(baskets[j] >= fruits[i] && used[j] == false)
                {
                    used[j] = true;
                    break;
                }
            }
        }

        for(int i = 0;i < used.size();i++)
        {
            if(used[i] == false)
            {
                unplaced++;
            }
        }

        return unplaced;
    }
};