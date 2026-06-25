class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();

        for(int i = 0;i < k;i++)
        {
            sum += cardPoints[i];
        }

        int curr = sum;
        for(int i = k - 1;i >= 0;i--)
        {
            //i will remove the last visited element
            curr -= cardPoints[i];

            //i will add the last unvisited from the last element
            curr += cardPoints[n - k + i];

            sum = max(sum,curr);
        }

        return sum;
    }
};