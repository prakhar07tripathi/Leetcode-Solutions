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
    private:
    void levelorder(queue<struct TreeNode*> &q, vector<vector<int>> &res){
    if(q.empty())return;
    vector<struct TreeNode*> ans;
    while(q.size()){
        ans.push_back(q.front());
        q.pop();
    }
    for(int i = 0; i < ans.size(); i++){
        if(ans[i]->left){
            q.push(ans[i]->left);
        }
        if(ans[i]->right){
            q.push(ans[i]->right);
        }
    }
    vector<int> data;
    for(int i = 0; i < ans.size(); i++){
        data.push_back(ans[i]->val);
    }
    res.push_back(data);
    levelorder(q, res);    
} 
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<struct TreeNode*>q;
        if(!root)return {};
        q.push(root);
        levelorder(q, res);
        return res;
    }
};