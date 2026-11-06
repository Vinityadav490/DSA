#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& st) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            st.insert(root);
        }
        if (prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }    
        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;
        makeGraph(root, NULL, adj, st);    
        int count = 0;
        for (auto leaf : st) {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);
            for (int level = 0; level <= distance; level++) {
                int sz = q.size();
                while (sz--) {
                    TreeNode* curr = q.front();
                    q.pop();
                    if (curr != leaf && st.count(curr)) {
                        count++;
                    }           
                    for (auto neighbor : adj[curr]) {
                        if (!visited.count(neighbor)) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
};