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
    TreeNode* RootToNode(TreeNode* &temp, TreeNode* &p, TreeNode* &q){
        if(!temp || temp == p || temp == q)return temp;

        TreeNode* templeft = RootToNode(temp->left, p, q);
        TreeNode* tempright = RootToNode(temp->right, p, q);

        if(templeft && tempright)return temp;

        return templeft != NULL ? templeft : tempright;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return RootToNode(root, p, q);
    }
};