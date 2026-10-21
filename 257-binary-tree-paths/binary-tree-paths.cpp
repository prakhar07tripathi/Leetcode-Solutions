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
    void height(TreeNode* &temp, string s, vector<string> &ans){
        if(!temp)return;
        if(!temp->left && !temp->right){
            s += to_string(temp->val);
            ans.push_back(s);
            return;
        }
        s += to_string(temp->val);
        s += "->";
        height(temp->left, s, ans);
        height(temp->right, s, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> ans;
        height(root, s, ans);
        return ans;
    }
};