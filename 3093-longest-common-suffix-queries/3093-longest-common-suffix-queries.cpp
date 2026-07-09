class TrieNode
{
    public:
    TrieNode* child[26];
    int idx;
    int length;
};
static constexpr int MAX_NODES = 600005;
static TrieNode pool[MAX_NODES];
static int ptr = 0;

class Trie {
public:
TrieNode* root;

    TrieNode* getNode()
    {
        TrieNode* node = &pool[ptr++];
        node->idx = -1;
        node->length = -1;
        for(int i = 0;i < 26;i++)
        {
            node->child[i] = nullptr;
        }
        return node;
    }

    Trie() 
    {
        root = getNode();
    }

    void insert(const string &word,int idx1,int size) 
    {
         TrieNode* curr = root;
            // Update root
    if(curr->idx == -1 ||
       curr->length > size ||
       (curr->length == size && idx1 < curr->idx))
    {
        curr->idx = idx1;
        curr->length = size;
    }
        for(int i = 0;i < word.size();i++)
        {
            int idx = word[i] - 'a';

            if(curr->child[idx] == nullptr)
            {
                curr->child[idx] = getNode();
            }

            curr = curr->child[idx]; 
            //when we are inserting the first word then idx will be updated to -1 to that word index ->later length will be checked and updated according to it
            if(curr->idx == -1 || curr->length > size || (curr->length == size && idx1 < curr->idx))
            {
                curr->idx = idx1;
                curr->length = size;
            }
        }
    }
    
    // bool search(string word) 
    // {
    //     TrieNode* curr = root;
    //     for(int i = 0;i < word.size();i++)
    //     {
    //         int idx = word[i] - 'a';
    //         //if the char is not found then the word is not present in the trie
    //         if(curr->child[idx] == nullptr)
    //         {
    //             return false;
    //         }

    //         curr = curr->child[idx];
    //     }

    //     //if the word is apples and the search word is apple we need to check that the word is ending or not
    //     return curr->isend;//we got the word that we are finding
    // }
    
    int startsWith(const string &prefix) 
    {

        TrieNode* curr = root;
        
        for(int i = 0;i < prefix.size();i++)
        {
            int idx = prefix[i] - 'a';

            if(curr->child[idx] == nullptr)
            {
                return curr->idx;
            }

            curr = curr->child[idx];
        }

        return curr->idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        ptr = 0;
        //convert this suffix into prefix and we can use trie data structure
        Trie node;
        vector<int>ans;
        for(int i = 0;i < wordsContainer.size();i++)
        {
            reverse(wordsContainer[i].begin(),wordsContainer[i].end());
            int size = wordsContainer[i].size();
            node.insert(wordsContainer[i],i,size);
        }

        for(int i = 0;i < wordsQuery.size();i++)
        {
            reverse(wordsQuery[i].begin(),wordsQuery[i].end());
            ans.push_back(node.startsWith(wordsQuery[i]));
        }

        return ans;
    }
};