class Solution {
public:
    vector<TreeNode*> solve(int start,int end){
        if(start>end) return {NULL};
        if(start==end){
            TreeNode*root=new TreeNode(start);
            return {root};
        }
        vector<TreeNode*>result;
        for(int i=start; i<=end; i++){
            vector<TreeNode*>left_bst=solve(start,i-1);
            vector<TreeNode*>right_bst=(solve(i+1,end));
            for(TreeNode*leftroot:left_bst){
                for(TreeNode*rightroot:right_bst){
                    TreeNode*root=new TreeNode(i);
                    root->left=leftroot;
                    root->right=rightroot;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};