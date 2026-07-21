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
    void pathWays(TreeNode* root, vector<string>&ans,string str){
        if(root == NULL)
        return;
       if(root->left == NULL && root->right == NULL){
        str+="->";
        str+=to_string(root->val);
        ans.push_back(str);
        return;
}
        str+= "->";
        str+=to_string(root->val);
         pathWays(root->left,ans,str);
         pathWays(root->right,ans,str);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
           
            return {};
        }
             vector<string>ans;
            if(root->left == NULL && root->right == NULL){
            ans.push_back( to_string(root->val));
            return ans;
            }
       

        string str = to_string(root->val);
        pathWays(root->left,ans,str);
         pathWays(root->right,ans,str);
        return ans;
    }
};