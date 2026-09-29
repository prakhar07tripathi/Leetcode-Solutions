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
            if(height(temp->left) == -1 || height(temp->right) == -1)return -1;
            if(abs(height(temp->left) - height(temp->right)) > 1){
                temp = NULL;
                return -1;
            }
            return max(1+height(temp->left),1+height(temp->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        /* BRUTE FORCE */
        // when we reach the leaf node then it  will always be balanced as both left and right are of height 0 so the base case will be true.
        // if(!root)return true;
        // // calculate the height of left subtree
        // int heightL = height(root->left);
        // // calculate the height of right subtree
        // int heightR = height(root->right);
        // // if their diff is greater than 1 return false
        // if(heightL - heightR > 1 || heightR - heightL > 1){
        //     return false;
        // }
        // // check this recursively such that even if one of the subtree returns false the ans will be false
        // return isBalanced(root->left) && isBalanced(root->right);
        /* OPTIMAL */
        // we only use the height function.
        // we return the height of the tree if the tree is balanced or else we return -1.
        // with this slight change we are able to find the answer in O(N) TC
        int x = height(root);
        if(x == -1)return false;
        return true;
    }
};