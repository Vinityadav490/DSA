class Solution {
public:
    vector<int> solve(TreeNode*root){
        if(root==NULL) return {0,0};
        vector<int>left=solve(root->left);
        vector<int>right=solve(root->right);
        int notTake=max(left[0],left[1])+max(right[0],right[1]);
        int take=root->val+left[0]+right[0];
        return {notTake,take};
    }
    int rob(TreeNode* root) {
        vector<int>ans=solve(root);
        return max(ans[0],ans[1]);
    }
};