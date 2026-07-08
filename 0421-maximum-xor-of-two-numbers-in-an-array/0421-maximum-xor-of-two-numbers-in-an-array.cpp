class TrieNode
{
    public:
    vector<TrieNode*>child;
    
    TrieNode()
    {
        //stores two values 0 and 1
        child = vector<TrieNode*>(2,nullptr);
    }


};
class Solution {
public:
       TrieNode* root;
      
    void insert(int n)
        {
            TrieNode* tempnode = root;
        bitset<32>b(n);
        for(int i = 31;i >= 0;i--)
        {
            
            if(tempnode->child[b[i]] == nullptr)
            {
                tempnode->child[b[i]] = new TrieNode();
            }

            tempnode = tempnode->child[b[i]];
        }

        }


    int findMaximumXOR(vector<int>& nums) {

        int ans = 0;
        root = new TrieNode();

        for(int ele : nums)
        {
            insert(ele);
        }

        for(int ele : nums)
        {
            ans = max(ans,findMax(ele));
        }
        return ans;
    }

    int findMax(int n)
    {
        bitset<32>b(n);
        int currans = 0;
        TrieNode* tempRoot = root;
        for(int i = 31;i >= 0;i--)
        {
            int tar = 1 - b[i];
            if(tempRoot->child[tar] != nullptr)
            {
                currans += (1 << i);
                tempRoot = tempRoot->child[tar];
            }
            else
            {
                tempRoot = tempRoot->child[b[i]];
            }
        }

        return currans;
    }
};