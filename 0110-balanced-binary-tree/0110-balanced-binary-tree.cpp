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
    int  maxDepth(TreeNode* root){
        if(!root) return 0;
         int leftDepth =maxDepth(root->left);
         if(leftDepth==-1){
            return -1;
         }
         int rightDepth = maxDepth(root->right);
         if(rightDepth==-1){
            return -1;
         }
         if(abs(leftDepth-rightDepth)>1){
            return -1;
         }
        return (max(maxDepth(root->left),maxDepth(root->right))+1);
    }
   
    bool isBalanced(TreeNode* root) {
        if(maxDepth(root)==-1){
            return false;
        }
        return true;
    }
};