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
    void preorder(TreeNode* &temp, map<int, map<int, multiset<int>>> &mpp, int pos, int depth){
        if(!temp)return;
        mpp[pos][depth].insert(temp->val);
        preorder(temp->left, mpp, pos-1, depth+1);
        preorder(temp->right, mpp, pos+1, depth+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int ,multiset<int>>> mpp;
        vector<vector<int>> res;
        preorder(root, mpp, 0, 0);
        for(const auto&[collumn, rows] : mpp){
            vector<int> columnvalues;
            for(const auto&[depth, values] : rows){
                for(int value : values){
                    columnvalues.push_back(value);
                }
            }
            res.push_back(columnvalues);
        }
        return res;
    }
};