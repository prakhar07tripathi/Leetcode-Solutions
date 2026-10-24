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
    void traversal(TreeNode* &temp, int val){
        if(!temp){
            temp = new TreeNode(val);
            return;
            }
        if(temp->val > val){
            traversal(temp->left, val);
        }
        else traversal(temp->right, val);
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root){
            root = new TreeNode(val);
            return root;
        }
        TreeNode* temp = root;
        traversal(temp, val);
        return root;
    }
};