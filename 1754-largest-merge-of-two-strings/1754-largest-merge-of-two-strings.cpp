class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        int i = 0,j = 0;

        int n1 = word1.size();
        int n2 = word2.size();

        while(i < n1 && j < n2)
        {
            if(word1[i] > word2[j])
            {
               merge += word1[i];
               i++;
            }
            else if(word2[j] > word1[i])
            {
                merge += word2[j];
                j++;
            }
            else
            {
                if(word1.substr(i) > word2.substr(j))
                {
                    merge += word1[i++];
                }
                else
                {
                    merge += word2[j++];
                }

            }
        }

        //may be there will be characters left after the loop ends also
        //like w1 = askfhf and w2 = ssf so remaining characters in w1 need to be added 
        while(i < n1) merge += word1[i++];
        while(j < n2) merge += word2[j++];

        return merge;
    }
};