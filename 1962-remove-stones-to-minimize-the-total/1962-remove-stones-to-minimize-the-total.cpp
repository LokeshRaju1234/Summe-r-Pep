class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
      
        priority_queue<pair<int,int>> pq;

        for(int i = 0;i < n;i++)
        {
            pq.push({piles[i],i});
        }

        while(k > 0)
        {
            auto temp = pq.top();
            pq.pop();

            piles[temp.second] = ceil((double)piles[temp.second] / 2);
            pq.push({piles[temp.second],temp.second});
            k--;
        }

        int sum = accumulate(piles.begin(),piles.end(),0);

        return sum;
    }
};