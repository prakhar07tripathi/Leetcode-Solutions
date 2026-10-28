/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void LevelOrder(queue<TreeNode*> &q, map<TreeNode*, TreeNode*> &parent){
        if(q.empty())return;
        vector<TreeNode*> temp;
        while(q.size()){
            temp.push_back(q.front());
            q.pop();
        }
        for(int i = 0; i < temp.size(); i++){
            if(temp[i]->left){
                parent[temp[i]->left] = temp[i];
                q.push(temp[i]->left);
            }
            if(temp[i]->right){
                parent[temp[i]->right] = temp[i];
                q.push(temp[i]->right);
            }
        }
        LevelOrder(q, parent);
    }
    void levelOrder(queue<TreeNode*> &q, vector<int> &ans, int k, map<TreeNode*, bool> &vis, map<TreeNode*, TreeNode*> &parent){
        if(q.empty())return;
        if(k == 0){
            while(q.size()){
            ans.push_back(q.front()->val);
            q.pop();
            }
            return;
        }
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left && !vis[temp->left]){
                q.push(temp->left);
                vis[temp->left] = true;
            }
            if(temp->right && !vis[temp->right]){
                q.push(temp->right);
                vis[temp->right] = true;
            }
            if(parent[temp] && !vis[parent[temp]]){
                q.push(parent[temp]);
                vis[parent[temp]] = true;
            }
        }
        levelOrder(q, ans, k - 1, vis, parent);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*, TreeNode*> parent;
        LevelOrder(q, parent);
        queue<TreeNode*> tar;
        tar.push(target);
        map<TreeNode*, bool> vis;
        vis[target] = true;
        vector<int> ans;
        levelOrder(tar, ans, k, vis, parent);
        return ans;
    }
};