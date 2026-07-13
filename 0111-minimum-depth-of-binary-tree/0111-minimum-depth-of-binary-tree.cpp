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
    int minDepth(TreeNode* root) {
        return depth(root);
    }

     int depth(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        int left = depth(root->left);
        int right = depth(root->right);

        //if it is skewed then we need to handle two cases
        if(root->left == nullptr)
        {
            return 1 + right;
        }
        if(root->right == nullptr)
        {
            return 1 + left;
        }

        //if both child exists then taken min path of left and right
        return  1 + min(left,right);
    }
};