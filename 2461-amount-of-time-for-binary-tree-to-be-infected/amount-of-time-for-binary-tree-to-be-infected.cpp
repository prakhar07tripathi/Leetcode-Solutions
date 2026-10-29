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
    void parent(TreeNode* temp, map<TreeNode*, TreeNode*> &par){
        queue<TreeNode*> q;
        q.push(temp);
        while(q.size()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                par[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                par[node->right] = node;
            }
        }
    }
    void FindStart(TreeNode* root, int start, TreeNode* &StartNode){
        if(!root)return;
        if(root->val == start)StartNode = root;
        FindStart(root->left, start, StartNode); 
        FindStart(root->right, start, StartNode); 
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*>par;
        parent(root, par);
        queue<TreeNode*> q;
        TreeNode* node = root;
        FindStart(root, start, node);
        q.push(node);
        map<TreeNode*, bool> visited;
        visited[node] = true;
        int radius = 0;
        while(q.size()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(par[temp] && !visited[par[temp]]){
                    q.push(par[temp]);
                    visited[par[temp]] = true;
                }
            }
            radius++;
        }
        return radius - 1;
    }
};