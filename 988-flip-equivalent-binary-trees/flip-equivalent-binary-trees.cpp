class Solution {
public:
    bool solve(TreeNode*r1,TreeNode*r2){
        if(r1==NULL&&r2==NULL) return true;
        if(r1==NULL||r2==NULL) return false;
        if(r1->val!=r2->val) return false;
        return (solve(r1->left,r2->left)&&solve(r1->right,r2->right))||
               (solve(r1->left,r2->right)&&solve(r1->right,r2->left));
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        return solve(root1,root2);
    }
};