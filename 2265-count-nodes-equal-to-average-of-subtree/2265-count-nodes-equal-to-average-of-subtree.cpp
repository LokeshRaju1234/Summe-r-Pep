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
    int sumOfNodes(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = sumOfNodes(root->left);
        int right = sumOfNodes(root->right);

        return root->val + left + right;
    }

    int countOfNodes(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }

        int left = countOfNodes(root->left);
        int right = countOfNodes(root->right);

        return 1 + left + right;
    }
    int averageOfSubtree(TreeNode* root) {

        if(root == NULL) return 0;

        int sum = sumOfNodes(root);
        int count = countOfNodes(root);
        int answer = 0;
        if((sum / count) == root->val){
            answer++;
        }

       int left =  averageOfSubtree(root->left);
        int right  = averageOfSubtree(root->right);

        answer += left + right;
        return answer;
    }
};