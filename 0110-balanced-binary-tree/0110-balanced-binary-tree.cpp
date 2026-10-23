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
    int getHigh(TreeNode* node)
    {
        if(node==nullptr) return 0;
        int leftHight=getHigh(node->left);
        if(leftHight==-1) return -1;
        int rightHight=getHigh(node->right);
        if(rightHight==-1) return -1;
        int result;
        if(abs(leftHight-rightHight)>1)
        {
            result=-1;
        }else
        {
            result=1+max(leftHight,rightHight);
        }
        return result;
    }
    bool isBalanced(TreeNode* root) {
        int result=getHigh(root);
        return result==-1? false:true; 
        
    }
};