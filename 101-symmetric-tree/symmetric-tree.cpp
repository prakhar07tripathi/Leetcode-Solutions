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
    bool symmetric(TreeNode* &tempL, TreeNode* &tempR){
    if(!tempL && !tempR)return true;
    else if((tempL && !tempR) || (tempR && !tempL))return false;
    return (tempL->val == tempR->val) && symmetric(tempL->left, tempR->right) && symmetric(tempL->right, tempR->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        // we must check levelwise  symmetry and hence we use DFS(level order traversal)
        TreeNode* tempL = root->left;
        TreeNode* tempR = root->right;
        if(!tempL && !tempR)return true;
        else if((tempL && !tempR) || (tempR && !tempL))return false;
        return symmetric(tempL, tempR);
    }
};