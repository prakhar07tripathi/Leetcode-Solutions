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
    TreeNode* LL(TreeNode* &temp){
        if(!temp)return NULL;
        TreeNode* left = LL(temp->left);
        TreeNode* right = LL(temp->right);
        if(temp->left){
            TreeNode* orgRight = temp->right;
            temp->right = temp->left;
            temp->left = nullptr;
            left->right = orgRight;
        }
        if(right)return right;
        if(left)return left;
        return temp;
        
    }
public:
    void flatten(TreeNode* root) {
        LL(root);
    }
};