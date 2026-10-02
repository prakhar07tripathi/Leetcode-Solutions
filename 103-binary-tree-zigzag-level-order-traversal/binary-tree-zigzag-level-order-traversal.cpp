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
    void levelOrder(queue<struct TreeNode*> &q, vector<vector<int>> &res, int &odd){
        if(q.empty())return;
        vector<struct TreeNode*>ans;
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
        if(!(odd%2)){
        for(int i = 0; i < ans.size(); i++){
            data.push_back(ans[i]->val);
        }
        }
        else{
            for(int i = ans.size() - 1; i >= 0; i--){
            data.push_back(ans[i]->val);
        }
        }
        odd+=1;
        res.push_back(data);
        levelOrder(q, res, odd);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<struct TreeNode*>q;
        q.push(root);
        if (!root)return {};
        vector<vector<int>> res;
        int odd = 0;
        levelOrder(q, res, odd);
        return res;
    }
};