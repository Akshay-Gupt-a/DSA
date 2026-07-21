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
    int search(TreeNode* root , vector<int>&inorder, int left, int right){
        for(int i = left ; i <= right; i++ ){
            if(root->val == inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>&preorder, vector<int>&inorder, int &idx, int left, int right){
        if(left > right){
            return NULL;
        }
        idx++;
        TreeNode* root = new TreeNode(preorder[idx]);
        int curr = search(root,inorder,left , right);
        TreeNode* le = helper(preorder, inorder, idx, left, curr-1);
        TreeNode* ri=  helper(preorder, inorder, idx, curr+1, right);
        root->left = le;
        root->right = ri;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = -1;
        return helper(preorder, inorder, idx, 0, n-1);
    }
};