class TrieNode
{
    public:
    TrieNode* child[26];
    bool isend;
    TrieNode()
    {
        for(int i = 0;i < 26;i++)
        {
            child[i] = nullptr;
        }
        isend = false;
    }
};

class Trie {
public:
TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
         TrieNode* curr = root;
        for(int i = 0;i < word.size();i++)
        {
            int idx = word[i] - 'a';

            if(curr->child[idx] == nullptr)
            {
                curr->child[idx] = new TrieNode();
            }

            curr = curr->child[idx]; 
        }

        curr->isend = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0;i < word.size();i++)
        {
            int idx = word[i] - 'a';
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
    
    bool startsWith(string prefix) {
        
        TrieNode* curr = root;

        for(int i = 0;i < prefix.size();i++)
        {
            int idx = prefix[i] - 'a';

            if(curr->child[idx] == nullptr)
            {
                return false;
            }

            curr = curr->child[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */