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
    int PreOrder(TreeNode* &temp, int &maxsum){
        if(!temp){
            return 0;
        }
        int leftsum = max(0, PreOrder(temp->left, maxsum));
        int rightsum = max(0, PreOrder(temp->right, maxsum));
        maxsum = max(maxsum, temp->val + leftsum + rightsum);
        return temp->val + max(leftsum, rightsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        TreeNode* temp = root;
        int maxsum = INT_MIN;
        PreOrder(temp, maxsum);
        return maxsum;
    }
};