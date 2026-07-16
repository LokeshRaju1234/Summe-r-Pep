/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx;
    unordered_map<int,int> mp;

    TreeNode* dfs(vector<int>& preorder,vector<int>& inorder,int left,int right,TreeNode* root)
    {
        if(left > right)
        {
            return NULL;
        }

        if(idx == preorder.size()) return NULL;

        int rootValue = preorder[idx++];
       TreeNode* node = new TreeNode(rootValue);
       int position = mp[rootValue];
       
       node->left = dfs(preorder,inorder,left,position - 1,root);
       node->right = dfs(preorder,inorder,position + 1, right,root);
       return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx = 0;

        for(int i = 0;i < inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode* root = NULL;
        return dfs(preorder,inorder,0,inorder.size() - 1,root);
    }
};