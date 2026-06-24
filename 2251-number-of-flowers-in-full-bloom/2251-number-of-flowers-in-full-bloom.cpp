class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) 
    {
        int p = people.size();
        vector<int>ans;

        vector<int>s;
        vector<int>e;
        for(int i = 0;i < flowers.size();i++)
        {
            s.push_back(flowers[i][0]);
            e.push_back(flowers[i][1]);
        }

        sort(s.begin(),s.end());
        sort(e.begin(),e.end());

        for(int ele : people)
        {
            //finds the first element > x
            auto st = upper_bound(s.begin(),s.end(),ele) - s.begin();
            auto end = lower_bound(e.begin(),e.end(),ele) - e.begin();

            ans.push_back(st - end);
        }

        return ans;
    }
};