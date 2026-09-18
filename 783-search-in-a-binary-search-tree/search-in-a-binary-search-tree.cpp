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
    void search(TreeNode* &temp, TreeNode* &ans, int val){
        if(!temp)return;
        if(temp->val == val){
            ans = temp;
            temp = NULL;
        }
        else if(temp->val > val){
            search(temp->left, ans, val);
        }
        else search(temp->right, ans, val);
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = NULL;
        search(root, ans, val);
        return ans;
    }
};