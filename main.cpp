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
    int sum(TreeNode* root, int& ans){
    
        if(root==NULL) return 0;

        int l=sum(root->left, ans);
        int r=sum(root->right, ans);

        int curr=root->val;

        ans=max(max(max(max(curr+l,curr+r),curr+l+r),ans),curr);
        return max(max(l+curr, r+curr),curr);
    
    }


    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        sum(root,ans);
        return ans;
    }
};