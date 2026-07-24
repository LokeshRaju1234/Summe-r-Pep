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
    int ans = 0;
    int maxdepth = -1;
    void dfs(TreeNode* root,int depth)
    {
        if(root == NULL)
        {
            return;
        }

        //for each depth the starting node will be your left node
        if(depth > maxdepth)
        {
            maxdepth = depth;
            ans = root->val;
        }


        dfs(root->left,depth + 1);
        dfs(root->right,depth + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};