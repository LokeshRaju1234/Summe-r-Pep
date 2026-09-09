class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        int commas = 1;

        while(start <= n)
            {
                long long end = start * 1000 - 1;

                long long numbers = min(n,end) - start + 1;

                ans += numbers * commas;

                start *= 1000;
                commas++;
            }

        return ans;
    }
};