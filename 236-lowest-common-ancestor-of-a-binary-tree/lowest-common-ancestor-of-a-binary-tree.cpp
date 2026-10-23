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
    bool RootToNode(TreeNode* &temp, TreeNode* &node, vector<TreeNode*> &res){
        if(!temp)return false;

        res.push_back(temp);

        if(temp == node){
            return true;
        }

        if(RootToNode(temp->left, node, res) || RootToNode(temp->right, node, res))return true;
        res.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> res1;
        vector<TreeNode*> res2;
        TreeNode* ans;
        RootToNode(root, p, res1);
        RootToNode(root, q, res2);
        int n = res1.size();
        int m = res2.size();
        if(m > n){
            for(int i = 0; i < n; i++){
                if(res1[i]->val == res2[i]->val)
                ans = res1[i];
            }
        }
        else {
            for(int i = 0; i < m; i++){
                if(res1[i]->val == res2[i]->val)
                ans = res1[i];
            }
        } 
        return ans;
    }
};