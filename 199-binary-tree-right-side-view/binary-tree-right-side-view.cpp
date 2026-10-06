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
    void helper(queue<TreeNode*> &q, vector<int> &res){
        if(q.empty())return;
        vector<TreeNode*>ans;
        res.push_back(q.front()->val);
        while(q.size()){
            ans.push_back(q.front());
            q.pop();
        }
        for(int i = 0; i < ans.size(); i++){
            if(ans[i]->right){
                q.push(ans[i]->right);
            }
            if(ans[i]->left){
                q.push(ans[i]->left);
            }
        }
        helper(q, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        // we keep track of the right element of each level
        // therefore we will use BFS(level order)traversal
        if(!root)return{};
        queue<TreeNode*> q;
        vector<int>res;
        q.push(root);
        helper(q,res);
        return res;
    }
};