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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == NULL)
        {
            return {};
        }
        vector<vector<int>>ans;
        vector<int> res;
        queue<TreeNode*>q;
        q.push(root);
        res.push_back(root->val);
        ans.emplace_back(res);

        res.clear();
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left)
                {
                    q.push(node->left);
                    res.push_back(node->left->val);
                }

                if(node->right)
                {
                    q.push(node->right);
                    res.push_back(node->right->val);
                }
            }

            if(!q.empty())
            {
                ans.emplace_back(res);
                res.clear();
            }
        }

        return ans;
    }
};