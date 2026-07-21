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
    int infect(TreeNode* root,int tar)
    {

        if(root == NULL)
        {
            return 0;
        }

        int left = infect(root->left,tar);
        int right = infect(root->right,tar);

        if(root->val == tar)
        {
            ans = max(left,right);
            return -1;
        }

        if(left < 0)
        {
            ans = max(ans,abs(left) + abs(right));
            return left - 1;
        }

        if(right < 0)
        {
            ans = max(ans,abs(left) + abs(right));
            return right - 1;
        }

        return 1 + max(left,right);
    }

    
    int amountOfTime(TreeNode* root, int start) {
        
        infect(root,start);
        return ans;
    }
};