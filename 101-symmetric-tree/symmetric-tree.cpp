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
    bool symmetric(queue<struct TreeNode*> &q){
        if(q.empty())return true;
        vector<struct TreeNode*> dup;
        while(q.size()){
            dup.push_back(q.front());
            q.pop();
        }
        for(int i = 0; i < dup.size(); i++){
            if(dup[i] == NULL)continue;
                q.push(dup[i]->left);
                q.push(dup[i]->right);
        }
        int i = 0;
        int j = dup.size() - 1;
        while(i < j){
            if((!dup[i] && dup[j]) || (dup[i] && !dup[j]))return false;
            else if(dup[i] && dup[j] && dup[i]->val != dup[j]->val)return false;
            i++;
            j--;
        }
        return symmetric(q);
    }
public:
    bool isSymmetric(TreeNode* root) {
        // we must check levelwise  symmetry and hence we use DFS(level order traversal)
        queue<struct TreeNode*> q;
        q.push(root);
        return symmetric(q);
    }
};