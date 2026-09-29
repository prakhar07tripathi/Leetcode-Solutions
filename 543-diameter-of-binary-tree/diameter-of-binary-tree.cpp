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
    int height(TreeNode* temp, int &maxdia){
        if(!temp) return 0;
        int l = height(temp->left, maxdia);
        int r = height(temp->right, maxdia);
        maxdia = max(maxdia, l+r);
        return 1 + max(l, r);
    }
    // int maxdiameter(TreeNode* temp, int &maxdia){
    //     if(!temp)return maxdia;
    //     int l = height(temp->left);
    //     int r = height(temp->right);
    //     maxdia = max(maxdia, l + r);
    //     return max(maxdiameter(temp->left, maxdia), maxdiameter(temp->right, maxdia));
    // }
    
    public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia = 0;
        height(root, maxdia);
        return maxdia;
    }
};