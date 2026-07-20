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
    vector<long long > sumLevel(TreeNode* root,queue<TreeNode*>q){
        vector<long long >ans;
        while(!q.empty()){
            int size = q.size();
            long long  sum = 0;
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                
                sum+=curr->val;
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            ans.push_back(sum);
        }
        return ans;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        vector<long long> ans = sumLevel(root,q);
        sort(ans.begin(),ans.end());
        int n = ans.size();
        if(n-k>=0){
            return ans[n-k];
        }
        return -1;
        
    }
};