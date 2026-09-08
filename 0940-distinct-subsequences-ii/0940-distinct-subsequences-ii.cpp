class Solution {
public:
const int mod =1e9 + 7;
    int solve(int i,string &s,vector<int>& last,int previousCount){
        if(i == s.length()) return previousCount;

        int curr = s[i] - 'a';
       
            long long newtotal = (2LL * previousCount - last[curr] + mod) % mod;
            last[curr] = previousCount;
            previousCount = newtotal;
            

        return solve(i + 1,s,last,previousCount);
    }
    int distinctSubseqII(string s) {
      
        vector<int>last(26,0);
       return  (solve(0,s,last,1) - 1 + mod) % mod;
    }
};