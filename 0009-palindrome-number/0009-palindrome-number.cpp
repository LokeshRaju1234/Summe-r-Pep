class Solution {
public:
    bool isPalindrome(int x) {
        string pali = to_string(x);
        int n = pali.size();
        int i = 0,j = pali.size() - 1;
        while(i <= j)
        {
            if(pali[i] != pali[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};