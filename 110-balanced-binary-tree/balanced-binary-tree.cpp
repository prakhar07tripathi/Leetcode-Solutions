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
    // we can check if the hieght gap of left and right subtree is <= 1
    // we apply DFS on each subtree and return false if heightL and heightR are at a gap more than 1
    private:
    int height(TreeNode* temp){
            if(!temp){
                return 0;
            }
            return max(1+height(temp->left),1+height(temp->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int heightL = height(root->left);
        int heightR = height(root->right);
        if(heightL - heightR > 1 || heightR - heightL > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};