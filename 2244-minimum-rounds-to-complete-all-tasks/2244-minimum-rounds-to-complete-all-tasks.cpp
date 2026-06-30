class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int &i : tasks)
        {
            mp[i]++;
        }

        int out = 0;

        for(auto &ele : mp)
        {
            if(ele.second ==1)
            {
                return -1;
            }
            if(ele.second % 3 == 0)
            {
                out += ele.second / 3;
            }
            else
            {
                out += (ele.second / 3) + 1;
            }
        }

        return out;
    }
};