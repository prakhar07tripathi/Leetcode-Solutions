/**
 * Definition for a binary tree temp.
 * struct Treetemp {
 *     int val;
 *     Treetemp *left;
 *     Treetemp *right;
 *     Treetemp() : val(0), left(nullptr), right(nullptr) {}
 *     Treetemp(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Treetemp(int x, Treetemp *left, Treetemp *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void LL(TreeNode* &temp, TreeNode* &prev){
        if(!temp)return;
        LL(temp->right, prev);
        LL(temp->left, prev);
        temp->right = prev;
        temp->left = NULL;
        prev = temp;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        LL(root, prev);
    }
};