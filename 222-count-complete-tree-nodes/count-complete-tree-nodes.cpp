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
    int RightHeight(TreeNode* temp){
        int depth = 0;
        while(temp){
            temp = temp->right;
            depth++;
        }
        return depth;
    }
    int LeftHeight(TreeNode* temp){
        int depth = 0;
        while(temp){
            temp = temp->left;
            depth++;
        }
        return depth;
    }
    int SubtreeNodes(TreeNode* temp){
        if(!temp) return 0;
        if(LeftHeight(temp) == RightHeight(temp))return pow(2, LeftHeight(temp)) - 1;
        return SubtreeNodes(temp->left) + SubtreeNodes(temp->right) + 1;
    }
public:
    int countNodes(TreeNode* root) {
        return SubtreeNodes(root);

        // int nodes = 0;
        // PreOrder(root, nodes);
        // return nodes;
    }
};