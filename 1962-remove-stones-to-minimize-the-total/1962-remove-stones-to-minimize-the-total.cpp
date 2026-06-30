class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
      int sum = 0;
        priority_queue<int> pq;

        for(int i = 0;i < n;i++)
        {
            pq.push(piles[i]);
        }

        while(k > 0)
        {
            pq.push((pq.top() + 1) / 2);
            pq.pop();
            k--;
        }

        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};