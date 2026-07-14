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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*>st;
        st.push(root);
        TreeNode* node = root;
        vector<int>ans;
        while(!st.empty()){
            TreeNode* currTop= st.top();
            if(node==NULL){
                ans.push_back(currTop->val);
                st.pop();
                if(currTop->right!=NULL){
                    st.push(currTop->right);
                    node =  currTop->right;
                }
                else{
                    node=NULL;
                }
                
            }
            else{
                if(currTop->left!=NULL){
                    st.push(currTop->left);
                    node = currTop->left;
                }
                else{
                    node=NULL;
                }
            }

        }
        return ans;
    }
};