class Solution {
public:
    int avgSum(TreeNode*root){
        int sum=0;
        int n=0;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0){
            TreeNode*node=q.front();
            q.pop();
            n++;
            sum+=node->val;
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        return sum/n;
    }
    void solve(TreeNode*root,int &count){
        if(root==NULL) return;
        if(avgSum(root)==root->val) count++;
        solve(root->left,count);
        solve(root->right,count);
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        solve(root,count);
        return count;
    }
};