class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int ei = 0,si = 0,len = INT_MAX,count_1 = 0;
        int s_index = 0;
        string str = "";
        while(ei < n)
        {
            if(s[ei++] == '1') count_1++;

            //whenever the substring got enough k ones then we got our substring with k ones
            //so update the length
            while(count_1 == k){

                if(ei - si < len)
                {
                    len = ei - si;
                    str = s.substr(si,len);
                }

                if(ei - si == len){
                  string curr = s.substr(si,ei - si);
                  if(curr < str){
                    str = curr;
                  }
                }

                if(s[si++] == '1') count_1--;
            }

        }

        // if(count_1 == 0) return "";

        // return len == INT_MAX ? "" : s.substr(s_index,len);
        return s == "" ? "" : str;
    }
};