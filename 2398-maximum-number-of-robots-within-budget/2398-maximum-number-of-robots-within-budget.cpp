class Solution {
public:

    bool possible(vector<int>& chargeTimes,
                  vector<int>& runningCosts,
                  long long budget,
                  int k)
    {
        if(k == 0) return true;

        int n = chargeTimes.size();

        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + runningCosts[i];
        }

        deque<int> dq;

        for(int i = 0; i < n; i++)
        {
            // Maintain decreasing deque for maximum chargeTime
            while(!dq.empty() &&
                  chargeTimes[dq.back()] <= chargeTimes[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            int l = i - k + 1;

            // Window of size k not formed yet
            if(l < 0) continue;

            // Remove indices outside current window
            while(!dq.empty() && dq.front() < l)
            {
                dq.pop_front();
            }

            long long maxCharge = chargeTimes[dq.front()];

            long long sumRunning =
                prefix[i + 1] - prefix[l];

            long long cost =
                maxCharge + 1LL * k * sumRunning;

            if(cost <= budget)
            {
                return true;
            }
        }

        return false;
    }

    int maximumRobots(vector<int>& chargeTimes,
                      vector<int>& runningCosts,
                      long long budget)
    {
        int n = chargeTimes.size();

        int l = 0;
        int h = n;
        int ans = 0;

        while(l <= h)
        {
            int mid = l + (h - l) / 2;

            if(possible(chargeTimes,
                        runningCosts,
                        budget,
                        mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return ans;
    }
};