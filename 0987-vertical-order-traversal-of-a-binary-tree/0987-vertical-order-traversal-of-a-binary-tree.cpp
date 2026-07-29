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
    map<int,vector<pair<int,int>>> mp;
    void dfs(TreeNode* root,int row,int col)
    {
        if(!root) return;

        mp[col].push_back({row,root->val});
        dfs(root->left,row + 1,col - 1);
        dfs(root->right,row + 1,col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       dfs(root,0,0); 

       vector<vector<int>> ans;

       for(auto& p : mp)
       {
        auto& it = p.second;
        sort(it.begin(),it.end());

        vector<int> temp;
        for(auto& n : it)
        {
            temp.push_back(n.second);
        }

        ans.push_back(temp);
       }

       return ans;
    }
};