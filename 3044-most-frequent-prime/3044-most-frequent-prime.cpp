class Solution {
public:
 bool isPrime(int num)
  {
      if(num <= 1) return false;
      
      for(int i = 2;i * i <= num;i++)
      {
          if(num % i == 0)
          {
              return false;
          }
      }
      
      return true;
  }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int dx [] = {-1,-1,-1,0,0,1,1,1};
        int dy [] = {-1,0,1,-1,1,-1,0,1};
        unordered_map<int,int>mp;
        int mx = INT_MIN;
        int element = -1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                for(int k = 0;k < 8;k++)
                {
                    int num = 0;
                    int x = i,y = j;
                    while(x >= 0 && x < n && y >= 0 && y < m)
                    {
                        num = num * 10 + mat[x][y];

                        if(num > 10 && isPrime(num) == true)
                        {
                            mp[num]++;
                            if(mp[num] > mx)
                            {
                                mx = mp[num];
                                element = num;
                            }
                            else if(mp[num] == mx && num > element)
                            {
                                element = num;
                            }
                        }
                        x = x + dx[k];
                        y = y + dy[k];
                    }
                }
            }
        }

        return element == -1 ? -1 : element;
    }
};