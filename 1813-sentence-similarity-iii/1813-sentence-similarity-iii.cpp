class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        

        int i = 0;

       vector<string>w1;
       vector<string>w2;

       stringstream ss1(sentence1);
       string word;
       while(ss1 >> word)
       {
        w1.push_back(word);
       }

       stringstream ss2(sentence2);
       while(ss2 >> word)
       {
        w2.push_back(word);
       }
       int n1 = w1.size(),n2 = w2.size();
       //checking the prefix and checking from begining
       while(i < n1 && i < n2 && w1[i] == w2[i])
       {
        i++;
       }

       int j = 0;

    //checking the prefix and checking from backside
       while(j < n1 - i && 
       j < n2 - i && w1[n1 - 1 - j] == w2[n2 - 1 - j])
       {
        j++;
       }

       return i + j >= min(n1,n2); 
    }
};