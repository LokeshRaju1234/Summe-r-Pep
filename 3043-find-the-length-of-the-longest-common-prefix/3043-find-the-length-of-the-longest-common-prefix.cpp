class TrieNode
{
    public:
    TrieNode* child[10];
    bool isend;
    TrieNode()
    {
        for(int i = 0;i < 10;i++)
        {
            child[i] = nullptr;
        }
        isend = false;
    }
};

class Trie {
public:
TrieNode* root;
    Trie() 
    {
        root = new TrieNode();
    }
    
    void insert(string word) 
    {
         TrieNode* curr = root;
        for(int i = 0;i < word.size();i++)
        {
            int idx = word[i] - '0';

            if(curr->child[idx] == nullptr)
            {
                curr->child[idx] = new TrieNode();
            }

            curr = curr->child[idx]; 
        }

        curr->isend = true;
    }
    
    bool search(string word) 
    {
        TrieNode* curr = root;
        for(int i = 0;i < word.size();i++)
        {
            int idx = word[i] - '0';
            //if the char is not found then the word is not present in the trie
            if(curr->child[idx] == nullptr)
            {
                return false;
            }

            curr = curr->child[idx];
        }

        //if the word is apples and the search word is apple we need to check that the word is ending or not
        return curr->isend;//we got the word that we are finding
    }
    
    int startsWith(string prefix) 
    {

        TrieNode* curr = root;
        int count = 0;
        for(int i = 0;i < prefix.size();i++)
        {
            int idx = prefix[i] - '0';

            if(curr->child[idx] == nullptr)
            {
                return count;
            }

            curr = curr->child[idx];
            count++;
        }

        return count;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* node = new Trie();
        for(int ele : arr1)
        {
            string s = to_string(ele);
            node->insert(s);
        }
        int maxLen = INT_MIN;
        for(int ele : arr2)
        {
            string s = to_string(ele);
            int len = node->startsWith(s);
            maxLen = max(maxLen,len);
        }

        return maxLen;
    }
};