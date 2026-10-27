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
    void leftSum(TreeNode* node,int& sum)
    {
        if (node == nullptr) return;
        // 叶节点
        if(node->left!=nullptr  &&node->left->left==nullptr && node->left->right==nullptr) 
        {
            sum+=node->left->val;
        }
        if(node->left)   leftSum(node->left,sum);
        if(node->right)  leftSum(node->right,sum);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        leftSum(root,sum);
        return sum;
    }
};