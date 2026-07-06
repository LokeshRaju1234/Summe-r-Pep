class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1,true);

        if (right >= 0) isPrime[0] = false;
        if (right >= 1) isPrime[1] = false;

        for(int i = 2;i * i <= right;i++)
        {
            if(isPrime[i])
            {
                for(int j = i * i;j <= right;j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        vector<int>ans = {-1,-1};
        int minDiff = INT_MAX;
        int lastPrime = -1;
        for(int i = left;i <= right;i++)
        {
            if(isPrime[i])
            {
                if(lastPrime != -1)
                {
                    if(i - lastPrime < minDiff)
                    {
                    minDiff = i - lastPrime;
                    ans[0] = lastPrime;
                    ans[1] = i;
                    }

                    if(minDiff <= 2)
                    {
                        return ans;
                    }
                }

                lastPrime = i;
            }
        }

        return ans;
        
    }
};