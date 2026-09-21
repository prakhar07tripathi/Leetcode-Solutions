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
    void depth(TreeNode* temp, int Depth, int& maxdepth){
        if(!temp){
            maxdepth = max(Depth, maxdepth);
            return;
        }
        depth(temp->left, Depth+1, maxdepth);
        depth(temp->right, Depth+1, maxdepth);
    }
public:
    int maxDepth(TreeNode* root) {
        int Depth = 0;
        int maxdepth = 0;
        depth(root, Depth, maxdepth);
        return maxdepth;
    }
};