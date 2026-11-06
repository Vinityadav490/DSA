class Solution {
public:
    void solve(TreeNode*root,string &s){
        if(root==NULL) {
            return;
        }
        s+=to_string(root->val);
        if(root->left!=NULL||root->right!=NULL){
            s+='(';
            solve(root->left,s);
            s+=')';
        }
        if(root->right!=NULL){
            s+='(';
            solve(root->right,s);
            s+=')';
        }
        return;
    }
    string tree2str(TreeNode* root) {
        string s="";
        solve(root,s);
        return s;
    }
};